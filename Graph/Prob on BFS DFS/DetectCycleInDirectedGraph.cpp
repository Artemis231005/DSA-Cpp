#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkDFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it: adj[node]) {
        if (!vis[it]) { // if adjacent node is not visited
            if (checkDFS(it, adj, vis, pathVis) == true) {
                return true;
            }
        } else if (pathVis[it] == 1) {  // if node has been previously visited and visited on same path
            return true;
        }      
    }

    pathVis[node] = 0;
    return false;
}

// TC: O(V + E)   SC: O(2V)
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i=0; i<V; i++) {
        if (!vis[i]) {
            if (checkDFS(i, adj, vis, pathVis) == true) {
                return true;
            }
        }
    }
    return false;
}

bool checkDFSOnlyVis(int node, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            if (checkDFSOnlyVis(it, adj, vis)) {
                return true;
            }

        } else if (vis[it] == 1) {      // Adjacent node is already in the current DFS path
            return true;
        }
    }

    vis[node] = 2;  // Completely processed
    return false;
}

// 0 = not visited
// 1 = currently in DFS path
// 2 = completely processed
// TC: O(V + E)   SC: O(V)
bool isCycleOnlyVis(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (vis[i] == 0) {
            if (checkDFSOnlyVis(i, adj, vis)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m, u, v;
    vector<int> adj[100];

    cout << "Enter the values of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter directed edges:\n";
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "\nUsing vis and pathVis: ";
    if (isCycle(n, adj)) {
        cout << "There is a cycle";
    } else {
        cout << "There is no cycle";
    }

    cout << "\nUsing only vis: ";
    if (isCycleOnlyVis(n, adj)) {
        cout << "There is a cycle";
    } else {
        cout << "There is no cycle";
    }
    return 0;
}