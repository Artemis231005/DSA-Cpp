#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkDFS(int node, int nodeColor, vector<int> &color, vector<int> adj[]) {
    color[node] = nodeColor;

    for (auto it: adj[node]) {
        if(color[it] == -1) {
            if (checkDFS(it, !nodeColor, color, adj) == false) {
                return false;
            }
        } else if (color[it] == nodeColor) {
            return false;
        }
    }
    return true;
}

// TC: O(V) + O(E)   SC: O(V)   (same TC and SC as normal DFS)
bool isBipartiteDFS(int V, vector<int> adj[]) {
    vector<int> color(V, -1);

    for (int i=0; i<V; i++) {
        if (color[i] == -1) {
            if (checkDFS(i, 0, color, adj) == false) {
                return false;
            }
        }
    }
    return true;
}

bool checkBFS(int start, vector<int> adj[], vector<int> &color) { // checks color for a component
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it: adj[node]) {
            if (color[it] == -1) {                          // If adjacent node is uncolored, assign it the opposite color
                color[it] = !color[node];
                q.push(it);
            } else if (color[it] == color[node]) {          // If adjacent node has the same color as node, graph is not bipartite
                return false;
            }
        }
    }
    return true;
}

// TC: O(V) + O(E)   SC: O(V)  (Same TC and SC as normal BFS)
bool isBipartiteBFS(int V, vector<int> adj[]) {
    vector<int> color(V, -1);

    for (int i=0; i<V; i++) {
        if (color[i] == -1) {
            if (checkBFS(i, adj, color) == false) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int V, k;
    vector<int> adj[100];

    cout << "Enter the number of nodes: ";
    cin >> V;

    cout << "Enter the adjacency list:\n";
    for (int i=0; i<V; i++) {
        cout << "Enter number of adjacent nodes for " << i << ": ";
        cin >> k;

        cout << "Enter adjacent nodes: ";
        for (int j=0; j<k; j++) {
            int node;
            cin >> node;
            adj[i].push_back(node);
        }
    }

    cout << "Using BFS: ";
    if (isBipartiteBFS(V, adj)) {
        cout << "Is bipartite";
    } else {
        cout << "Is not bipartite";
    }

    cout << "\nUsing DFS: ";
    if (isBipartiteDFS(V, adj)) {
        cout << "Is bipartite";
    } else {
        cout << "Is not bipartite";
    }
    return 0;
}