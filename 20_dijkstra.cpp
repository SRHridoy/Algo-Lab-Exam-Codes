/*Author : Md. Sohanur Rahman Hridoy
20. Write a program to implement single-source shortest path algorithm using *Dijkstra's algorithm*.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V, INT_MAX);

    distTo[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node]) {
            int v = it.first;
            int w = it.second;
            if (dis + w < distTo[v]) {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }
    return distTo;
}

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int S;
    cin >> S;

    vector<int> distances = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++) {
        cout << distances[i] <<" ";
    }

    return 0;
}
