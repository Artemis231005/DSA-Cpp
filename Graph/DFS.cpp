#include <iostream>
#include <vector>
using namespace std;

void dfsTraversal(int node, vector<int> adj[], int vis[], vector<int> &ans) {
    vis[node] = 1;
    ans.push_back(node);
    for (auto it: adj[node]) {
        if (!vis[it]) {
            dfsTraversal(it, adj, vis, ans);
        }
    }
}

vector<int> dfsHelper(int N, vector<int> adj[]) {
    vector<int> ans;
    int start = 1;
    int vis[100] = {0};
    
    for (int i = 1; i <= N; i++) {     // loop through all nodes (handles case of disconnected grpahs also otherwise just do dfsTraversal(i, adj, vis, ans);)
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

    cout << "Enter the edges: " << endl;
    for (int i=0; i<m; i++) { 
        cin >> u >> v;                      
        adj[u].push_back(v);                        
        adj[v].push_back(u);
    }

    vector<int> ans = dfsHelper(n, adj);
    cout << "DFS Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}