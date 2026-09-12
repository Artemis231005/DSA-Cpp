#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detectCycleBFS(int src, vector<int> adj[], vector<int> &vis) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode: adj[node]) {
            if (!vis[adjNode]) {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            } else if (parent != adjNode) {  // some node is visited but that node isn't the node from which current node came from or 
                // if the neighbour is already visited and is not the parent, then a cycle exists.
                return true;
            }
        }
    }

    return false;
}

// TC: O(N + 2E)  SC: O(N)
bool isCycleBFS(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);

    for (int i=0; i<V; i++) {
        if (!vis[i]) {
            if (detectCycleBFS(i, adj, vis) == true) {
                return true;
            }
        }
    }

    return false;
}

bool detectDFS(int node, int parent, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;

    for (auto adjNode: adj[node]) {
        if (!vis[adjNode]) {
            if (detectDFS(adjNode, node, vis, adj) == true) {
                return true;
            } 
        } else if (adjNode != parent) {
            return true;
        }
    }
    return false;
}

// TC:O(N + 2E) + O(N) (forl= loop of connected comp)  SC: O(N) (recursion stack space and vis array)
bool isCycleDFS(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);

    for (int i=0; i<V; i++) {
        if (!vis[i]) {
            if(detectDFS(i, -1, vis, adj) == true) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m, u, v;
    cout << "Enter the values of nodes and edges: ";
    cin >> n >> m;

    vector<int> adj[100];

    cout << "Enter edges:\n";
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Using BFS: ";
    if (isCycleBFS(n, adj)) {
        cout << "There is a cycle";
    } else {
        cout << "There is no cycle";
    }

    cout << "\nUsing DFS: ";
    if (isCycleDFS(n, adj)) {
        cout << "There is a cycle";
    } else {
        cout << "There is no cycle";
    }

    return 0;
}