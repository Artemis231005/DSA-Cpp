#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// TC: O(V + E) (same as BFS algo)   SC: O(V) (queue and indegree arr)
vector<int> kahnAlgo(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    for (int node=0; node<V; node++) {
        for (auto it: adj[node]) {
            indegree[it]++;

        }
    }    

    queue<int> q;
    for (int i=0; i<V; i++) {
        if (indegree[i] == 0) {    // There will alwas be at least 1 node with indegree 0 in a DAC*
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        // node is in ans, so remove its outgoing edges
        for (auto it: adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return ans;
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

    vector<int> ans = kahnAlgo(n, adj);

    cout << "Topological Sorted Order Using Kahn's Algorithm: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}