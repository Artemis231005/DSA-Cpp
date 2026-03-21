#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool dfs(int node, int target, vector<int> adj[], vector<int>& vis) {
    if(node == target) {
        return true;
    }

    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, target, adj, vis))
                return true;
        }
    }
    return false;
}

// TC: O(ElogE)
int findMSTSum(int V, vector<pair<int, pair<int,int>>> &edges) {
    sort(edges.begin(), edges.end());

    vector<int> adj[100];
    int mstWt = 0;

    for(auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        vector<int> vis(V, 0);

        if(!dfs(u, v, adj, vis)) {
            mstWt += wt;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    return mstWt;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, pair<int,int>>> edges;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({w, {u, v}});
    }

    cout << "MST Weight: " << findMSTSum(V, edges);
    return 0;
}