#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5+123;
vector<int>adj[mx];
vector<int>vis(mx,false);
vector<bool>isNode(mx,false);
void dfs(int node){
    vis[node] = true;
    for(auto u:adj[node]){
        if(vis[u]==false){
            vis[u] = true;
            dfs(u);
        }
    }
}

int main(){

    int V,E;
    cin >> V>> E;

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        isNode[u] = true;
        isNode[v] = true;
    }

    int connectedComponent = 0;
    for(int i = 0; i < V; i++){
        if(vis[i] == false and isNode[i]== true){
            connectedComponent++;
            dfs(i);
        }
    }
    if(connectedComponent==1){
        cout << "Conncected!" << endl;
    }else{
        cout << "Disconnected!" << endl;
    }
}