#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

vector<int>bellman_ford(int v, vector<vector<int>>edges, int s){
    vector<int>dist(v,INF);
    dist[s] = 0;
    for(int i = 0; i < v-1; i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u]!=INF and dist[u]+wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(auto it:edges){
        int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u]!=INF and dist[u]+wt < dist[v]){
                return {-1};
            }
    }

    return dist;
}

int main(){

    int V,E;
    cin >> V>> E;

    vector<vector<int>>edges;
    for(int i = 0; i < E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    int s;
    cin >> s;
    
    vector<int>dist = bellman_ford(V,edges,s);

    //For 1 based node:
    for(int i = 1; i <= V; i++){
        if(dist[i]==INF)cout << i << " is unreachable from source " << s << endl;
        else cout << dist[i] << " ";

    }
}