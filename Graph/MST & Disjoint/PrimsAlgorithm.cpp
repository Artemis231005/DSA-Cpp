#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(E log V)   SC: O(V + E)
vector<pair<int, int>> primMST(int V, vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {weight, node}

    vector<int> vis(V, 0);
    vector<pair<int, int>> mst;

    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq2; // {weight, node, parent}
    pq2.push({0, 0, -1});

    while (!pq2.empty()) {
        int wt = pq2.top()[0];
        int node = pq2.top()[1];
        int parent = pq2.top()[2];
        pq2.pop();

        if (vis[node]) {
            continue;
        }

        vis[node] = 1;

        if (parent != -1) {
            mst.push_back({parent, node});
            cout << parent << " - " << node << " : " << wt << endl;
        }

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (!vis[adjNode]) {
                pq2.push({edgeWt, adjNode, node});
            }
        }
    }
    return mst;
}

/*
- A spanning tree of a connected undirected graph is a connected, cycle-free subgraph that contains all the vertices of the original graph.
If the orignial graph had a cycle,it will remove an edge to break that cycle. 
A ST has exactly N - 1 edges and contains no cycle.

- An MST (Minimum Spanning Tree) is a spanning tree of a weighted, connected, undirected graph having the minimum possible total edge weight.

- If each edge has distinct weight, then there will be only 1 mst and it will be unique.

- A complete undirected graph with N vertices has N^(N - 2) different spanning trees (Cayley's formula).
Example: For a complete graph with 3 vertices (K3): Number of spanning trees = 3^(3 - 2) = 3.

- To obtain a spanning tree from a connected graph with N vertices and E edges, we need to remove exactly E - (N - 1) edges.
The resulting graph will have exactly N - 1 edges and no cycle.
*/

int main() {
    int V, E;
    cout << "Enter number of nodes and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[100];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    cout << "\nEdges in MST:\n";
    primMST(V, adj);

    return 0;
}