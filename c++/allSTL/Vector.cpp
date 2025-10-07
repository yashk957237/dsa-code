#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> vec;

    //initialise vec, here emplace_back == push_back;
    vec.push_back(1);
    vec.emplace_back(2);
    vec.push_back(0);

    //size of vec el
    cout<<vec.size();

    //print vec el
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}