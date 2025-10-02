require 'set'
require 'priority_queue'

class Graph
  def initialize
    @adj = Hash.new { |h, k| h[k] = [] }
  end

  def add_edge(u, v, w, undirected = true)
    @adj[u] << [v, w]
    @adj[v] << [u, w] if undirected
  end

  def dijkstra(start)
    dist = Hash.new(Float::INFINITY)
    prev = {}
    dist[start] = 0

    pq = PriorityQueue.new
    pq[start] = 0

    until pq.empty?
      u = pq.delete_min[0]
      @adj[u].each do |v, w|
        alt = dist[u] + w
        if alt < dist[v]
          dist[v] = alt
          prev[v] = u
          pq[v] = alt
        end
      end
    end

    return dist, prev
  end

  def shortest_path(start, target)
    dist, prev = dijkstra(start)
    return nil unless dist[target] < Float::INFINITY

    path = []
    u = target
    while u
      path.unshift(u)
      u = prev[u]
    end
    path
  end
end