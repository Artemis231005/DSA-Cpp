#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dfsTraversal(int n, vector<int> adj[]) {
    vector<int> vis(n + 1, 0);
    vector<int> ans;

    for (int start = 1; start <= n; start++) {
        if (vis[start] == 0) {
            stack<int> st;
            st.push(start);
            vis[start] = 1;

            while (!st.empty()) {
                int node = st.top();
                st.pop();
                ans.push_back(node);

                // Push neighbors in reverse order for correct traversal
                for (int i = adj[node].size() - 1; i >= 0; i--) {
                    int neigh = adj[node][i];
                    if (vis[neigh] == 0) {
                        vis[neigh] = 1;
                        st.push(neigh);
                    }
                }
            }
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

    vector<int> ans = dfsTraversal(n, adj);

    cout << "Iterative DFS Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
