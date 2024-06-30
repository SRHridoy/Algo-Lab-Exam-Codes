#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<pair<int,int>>> adj, int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(v,INT_MAX);

    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node]){
            int v = it.first;
            int w = it.second;
            if(dis+w<dist[v]){
                dist[v] = dis+w;
                pq.push({dis+w,v});
            }
        }
    }
    return dist;
}

int main(){

    int V,E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back({v-1,w});
        //adj[v].push_back(u,w);
    }

    int s;
    cin >> s;
    s--;

    vector<int> dist = dijkstra(V,adj,s);
    for(auto u:dist){
        if(u == INT_MAX)cout << "INF" << " ";

        else cout << u << " ";
    }
}