#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;


vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int source) {
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, source); // (distance, node) //minheap

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main() {

    int n = 6;
    vector<vector<pair<int, int>>> adj(n);

    auto add_edge = [&](int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    };

    add_edge(0, 1, 7);
    add_edge(0, 2, 9);
    add_edge(0, 5, 14);
    add_edge(1, 2, 10);
    add_edge(1, 3, 15);
    add_edge(2, 3, 11);
    add_edge(2, 5, 2);
    add_edge(3, 4, 6);
    add_edge(4, 5, 9);

    int source = 0;
    vector<int> dist = dijkstra(n, adj, source);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Distance from source to node " << i << " is infinity" << endl;
        } else {
            cout << "Distance from source to node " << i << " is " << dist[i] << endl;
        }
    }

    return 0;
}