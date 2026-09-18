#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it: adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, st, adj);
        }
    }

    st.push(node);  // no neighbours to make dfs calls for
}

// TC: O(V + E) (same as dfs for DAC)   SC: O(V) (recursion stack + stack + vis arr)
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i=0; i<V; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
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

    vector<int> ans = topoSort(n, adj);

    cout << "Topological Sort: ";
    for (auto it : ans) {
        cout << it << " ";
    }

    cout << endl;
    return 0;
}