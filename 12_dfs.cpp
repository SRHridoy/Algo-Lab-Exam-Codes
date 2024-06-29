#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5+123;
vector<int>adj[mx];
vector<int>vis(mx,false);

void dfs(int node){
    vis[node] = true;
    cout << node << " ";
    for(auto u:adj[node]){
        if(vis[u]==false){
            vis[u] = true;
            dfs(u);
        }
    }
}

int main(){

    int V,E;
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    int startNode;
    cin >> startNode;
    dfs(startNode);

    // for(int i = 0; i < V; i++){
    //     cout << dfs(i) << " ";
    // }
}