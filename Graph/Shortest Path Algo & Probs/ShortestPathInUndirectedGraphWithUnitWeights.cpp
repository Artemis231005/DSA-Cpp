#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(V + E) (BFS)   SC: O(V + E) (adjacency list + queue + dist)
vector<int> getShortestPath(vector<vector<int>> &edges, int N, int M, int src) {
    vector<int> adj[100];
    for (auto it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> dist(N, 1e9);
    dist[src] = 0;
    queue<int> q;// Since all edges are 1, no need for data structure for sorting dists, they will increase by level & each will have the same dist
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if (dist[it] > dist[node] + 1) {
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }

    vector<int> ans(N, -1);
    for (int i=0; i<N; i++) {
        if (dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}

int main() {
    int n, m, u, v, src;
    
    cout << "Enter the values of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;

    cout << "Enter undirected edges:\n";
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges.push_back({u, v});
    }

    cout << "Enter source node: ";
    cin >> src;

    vector<int> ans = getShortestPath(edges, n, m, src);

    cout << "Shortest distances from source: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}