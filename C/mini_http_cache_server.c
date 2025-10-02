/* mini_http_cache_server.cpp
 *
 * Complex single-file C++17 program:
 * - TCP listener + thread pool
 * - Minimal HTTP GET handler
 * - In-memory LRU cache with std::unordered_map + std::list
 * - MIME type detection
 * - RAII + smart pointers
 * - Graceful shutdown
 */

#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

/*** Utility ***/
static volatile sig_atomic_t stopRequested = 0;
void handleSigint(int) { stopRequested = 1; }

string nowStr() {
    time_t t = time(nullptr);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&t));
    return buf;
}
#define LOG(x) cerr << "[" << nowStr() << "] " << x << "\n"

/*** Thread Pool ***/
class ThreadPool {
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex m;
    condition_variable cv;
    bool stopping = false;
public:
    ThreadPool(size_t n) {
        for(size_t i=0;i<n;i++) {
            workers.emplace_back([this]{
                while(true) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(m);
                        cv.wait(lock, [&]{ return stopping || !tasks.empty(); });
                        if(stopping && tasks.empty()) return;
                        task = move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }
    void enqueue(function<void()> f) {
        {
            unique_lock<mutex> lock(m);
            tasks.push(move(f));
        }
        cv.notify_one();
    }
    void shutdown() {
        {
            unique_lock<mutex> lock(m);
            stopping = true;
        }
        cv.notify_all();
        for(auto &w: workers) w.join();
    }
};

/*** LRU Cache ***/
class LRUCache {
    struct Entry { string key; vector<char> data; };
    size_t capacity, currentSize = 0;
    list<Entry> items;
    unordered_map<string, list<Entry>::iterator> map;
    mutex m;
public:
    LRUCache(size_t cap): capacity(cap) {}
    optional<vector<char>> get(const string &key) {
        lock_guard<mutex> lock(m);
        auto it = map.find(key);
        if(it==map.end()) return {};
        items.splice(items.begin(), items, it->second);
        return it->second->data;
    }
    void put(const string &key, vector<char> data) {
        lock_guard<mutex> lock(m);
        size_t sz = data.size();
        if(sz > capacity) return;
        if(auto it = map.find(key); it!=map.end()) {
            currentSize -= it->second->data.size();
            items.erase(it->second);
            map.erase(it);
        }
        while(currentSize + sz > capacity && !items.empty()) {
            currentSize -= items.back().data.size();
            map.erase(items.back().key);
            items.pop_back();
        }
        items.push_front({key, move(data)});
        map[key] = items.begin();
        currentSize += sz;
    }
};

/*** HTTP Helpers ***/
string guessMime(const string &path) {
    if(path.ends_with(".html")||path.ends_with(".htm")) return "text/html";
    if(path.ends_with(".css")) return "text/css";
    if(path.ends_with(".js")) return "application/javascript";
    if(path.ends_with(".png")) return "image/png";
    if(path.ends_with(".jpg")||path.ends_with(".jpeg")) return "image/jpeg";
    if(path.ends_with(".gif")) return "image/gif";
    if(path.ends_with(".txt")) return "text/plain";
    return "application/octet-stream";
}

/*** Global state ***/
static unique_ptr<LRUCache> cache;
static string wwwRoot;

/*** Client handler ***/
void handleClient(int fd) {
    char buf[4096];
    int n = recv(fd, buf, sizeof(buf)-1, 0);
    if(n<=0) { close(fd); return; }
    buf[n]=0;
    string method, path, version;
    {
        stringstream ss(buf);
        ss >> method >> path >> version;
    }
    if(method!="GET") {
        string resp="HTTP/1.0 405 Method Not Allowed\r\n\r\n";
        send(fd, resp.c_str(), resp.size(), 0);
        close(fd); return;
    }
    if(path=="/") path="/index.html";
    if(path.find("..")!=string::npos) {
        string resp="HTTP/1.0 403 Forbidden\r\n\r\n";
        send(fd, resp.c_str(), resp.size(), 0);
        close(fd); return;
    }
    string fullPath=wwwRoot+path;

    // Try cache
    auto cdata = cache->get(fullPath);
    if(cdata) {
        string hdr="HTTP/1.0 200 OK\r\nContent-Length: "+to_string(cdata->size())
                 +"\r\nContent-Type: "+guessMime(fullPath)+"\r\n\r\n";
        send(fd, hdr.c_str(), hdr.size(), 0);
        send(fd, cdata->data(), cdata->size(), 0);
        close(fd); return;
    }

    // Load file
    ifstream f(fullPath, ios::binary);
    if(!f) {
        string resp="HTTP/1.0 404 Not Found\r\n\r\n";
        send(fd, resp.c_str(), resp.size(), 0);
        close(fd); return;
    }
    vector<char> data((istreambuf_iterator<char>(f)), {});
    cache->put(fullPath, data);
    string hdr="HTTP/1.0 200 OK\r\nContent-Length: "+to_string(data.size())
             +"\r\nContent-Type: "+guessMime(fullPath)+"\r\n\r\n";
    send(fd, hdr.c_str(), hdr.size(), 0);
    send(fd, data.data(), data.size(), 0);
    close(fd);
}

/*** Main server loop ***/
int main(int argc,char**argv){
    if(argc<4) {
        cerr<<"Usage: "<<argv[0]<<" <port> <www-root> <cache-bytes>\n"; return 1;
    }
    int port=stoi(argv[1]);
    wwwRoot=argv[2];
    size_t cacheBytes=stoull(argv[3]);
    cache=make_unique<LRUCache>(cacheBytes);
    signal(SIGINT, handleSigint);

    int listenfd=socket(AF_INET,SOCK_STREAM,0);
    int one=1; setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&one,sizeof(one));
    sockaddr_in addr{}; addr.sin_family=AF_INET; addr.sin_port=htons(port);
    addr.sin_addr.s_addr=INADDR_ANY;
    bind(listenfd,(sockaddr*)&addr,sizeof(addr));
    listen(listenfd,128);

    LOG("Listening on port "<<port);
    ThreadPool pool(thread::hardware_concurrency());

    while(!stopRequested){
        sockaddr_in cli; socklen_t len=sizeof(cli);
        int c=accept(listenfd,(sockaddr*)&cli,&len);
        if(c<0) continue;
        pool.enqueue([c]{ handleClient(c); });
    }

    LOG("Shutting down...");
    pool.shutdown();
    close(listenfd);
    return 0;
}
