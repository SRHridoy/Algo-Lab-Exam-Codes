#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5+123;
vector<int>adj[mx];
vector<bool>vis(mx,false);
stack<int>st;

void topo_sort(int node){
    vis[node] = true;
    for(auto u:adj[node]){
        if(vis[u] == false){
            topo_sort(u);
        }
    }
    st.push(node);
}

int main(){

    int V,E;
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 0; i < V; i++){
        if(vis[i]==false){
            topo_sort(i);
        }
    }                   
    while(!st.empty()){
        int n = st.top();
        st.pop();
        cout << n << " ";
    }

}