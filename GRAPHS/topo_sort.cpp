// kahns algorigthm for topological sorting of a directed acyclic graph (DAG)
/*


indegree array to keep track of in-degrees of all vertices
1. Initialize the indegree of all vertices to 0.
2. For each directed edge (u, v) in the graph, increment the indegree of vertex v by 1.
3. Initialize a queue and enqueue all vertices with indegree 0.
4. Initialize an empty list to store the topological order.


*/


#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<int> topo_sort(int n, const vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topo_order;
}