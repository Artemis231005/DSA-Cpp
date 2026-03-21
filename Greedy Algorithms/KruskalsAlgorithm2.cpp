#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// TC: O(ElogE)
int findMSTSum(vector<vector<int>> adj[], int v) {
    vector<pair<int, pair<int, int>>> edges;
    for (int i=0; i<v; i++) {
        for (auto it: adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }

    DisjointSet ds(v);
    sort(edges.begin(), edges.end());
    int mstWt = 0;

    for (auto it: edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUPar(u) != ds.findUPar(v)) {
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstWt;
}

int main() {
    int v, E;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> E;

    vector<vector<int>> adj[100];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    cout << "MST Weight: " << findMSTSum(adj, v);
    return 0;
}