#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5+123;
vector<int>adj[mx];
vector<bool>vis(mx,false);

vector<int>bfs(int node){
    vector<int>reachableNodes;
    queue<int>q;
    q.push(node);;
    vis[node] = true;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        reachableNodes.push_back(n);
        for(auto u:adj[n]){
            if(vis[u]==false){
                vis[u] = true;
                q.push(u);
            }
        }
    }
    return reachableNodes;
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
    vector<int>reachableNodes = bfs(startNode);

    for(auto node:reachableNodes)cout << node << " ";
}