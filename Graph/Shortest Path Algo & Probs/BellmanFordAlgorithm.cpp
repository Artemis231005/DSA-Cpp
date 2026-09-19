#include <iostream>
#include <vector>
using namespace std;

// Bellman-Ford works with negative edge weights
// It can also detect negative weight cycles
// It takes more time (quad) as compared to djikistra(ElogV) so prefer djikistra whenever you are guaranteed non -ve edge wts

// TC: O(V * E)   SC: O(V + E)
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for (int i=0; i<V; i++) {       // relaxation will be done for V-1 times
        for (auto it: edges) {      // relaxation will be done for all edges
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Vth relaxtion done to detect if a negative cycle exists in graph
    for (auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1};
        }
    }

    return dist;
}

int main() {
    int V, E;
    cout << "Enter number of nodes and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter directed edges and their weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> ans = bellmanFord(V, edges, src);

    if (ans.size() == 1 && ans[0] == -1) {
        cout << "Negative weight cycle exists" << endl;
    } else {
        cout << "Shortest distances from source:\n";

        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " : ";
            if (ans[i] == 1e8) {
                cout << "INF";
            } else {
                cout << ans[i];
            }

            cout << endl;
        }
    }

    return 0;
}