#include <iostream>
#include <vector>
using namespace std;

void dfsProvinces(int node, vector<int> adj[], int vis[]) {
    vis[node] = 1;

    for (int i : adj[node]) {
        if (!vis[i]) {
            dfsProvinces(i, adj, vis);
        }
    }
}

// Count the number of connected components (provinces)
int noOfProvinces(int n, vector<int> adj[]) {
    int vis[100] = {0};
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            count++;
            dfsProvinces(i, adj, vis);
        }
    }
    return count;
}

void dfsTraversal(int node, vector<int> adj[], int vis[], vector<int> &ans) {
    vis[node] = 1;
    ans.push_back(node);

    for (int i : adj[node]) {
        if (!vis[i]) {
            dfsTraversal(i, adj, vis, ans);
        }
    }
}

vector<int> dfsHelper(int n, vector<int> adj[]) {
    vector<int> ans;
    int vis[100] = {0};

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfsTraversal(i, adj, vis, ans);
        }
    }

    return ans;
}

int main() {
    int n, m, u, v;
    cout << "Enter the values of n and m: ";
    cin >> n >> m;

    vector<int> adj[100];

    cout << "Enter edges:\n";
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Number of Provinces: " << noOfProvinces(n, adj) << endl;

    vector<int> ans = dfsHelper(n, adj);
    cout << "DFS Traversal: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}