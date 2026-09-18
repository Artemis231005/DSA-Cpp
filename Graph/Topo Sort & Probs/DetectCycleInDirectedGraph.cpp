#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// TC: O(V + E)   SC: O(V) (indegree array + queue)
bool detectCycle(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    for (int node = 0; node < V; node++) {
        for (auto it : adj[node]) {
            indegree[it]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {   // Check whether it DG can be processed like a DAG, A DAG always has at least one node with indegree 0.
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        count++;

        // Remove outgoing edges
        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If all V nodes were able to be processed, no cycle exists
    // Otherwise, a cycle exists
    return count != V;
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

    if (detectCycle(n, adj)) {
        cout << "Cycle exists in the directed graph" << endl;
    }
    else {
        cout << "No cycle exists in the directed graph" << endl;
    }

    return 0;
}