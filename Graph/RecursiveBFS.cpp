#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfsTraversal(vector<int> adj[], queue<int> &q, vector<int> &vis, vector<int> &ans) {
    if (q.empty()) {
        return;
    }

    int node = q.front();
    q.pop();
    ans.push_back(node);

    for (int it : adj[node]) {
        if (vis[it] == 0) {
            vis[it] = 1;
            q.push(it);
        }
    }
    bfsTraversal(adj, q, vis, ans);
}

vector<int> bfsTraversalHelper(int n, vector<int> adj[]) {
    vector<int> vis(n + 1, 0);
    vector<int> ans;
    queue<int> q;

    vis[1] = 1;
    q.push(1);

    bfsTraversal(adj, q, vis, ans);
    return ans;
}

int main() {
    int n, m, u, v;
    cout << "Enter the values of n and m: ";
    cin >> n >> m;

    vector<int> adj[100];

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "BFS Traversal of graph is: ";

    vector<int> ans = bfsTraversalHelper(n, adj);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
