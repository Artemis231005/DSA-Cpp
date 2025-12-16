#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

vector<int> BFSTraversal(int N, vector<int> adj[]) {         // TC: O(N) + O(2E) (all nodes visited once & then all its edges visited     
    // in for loop)      SC: O(3N) (queue, vis, ans)         N is number of nodes

    vector<int> ans;
    int vis[100] = {0};
    queue<int> q;

    // Loop through all nodes to handle disconnected graph
    for (int start = 1; start <= N; start++) {                
        if (!vis[start]) {
            vis[start] = 1;
            q.push(start);     

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (auto it: adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
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

    cout << "Enter the edges: " << endl;
    for (int i=0; i<m; i++) { 
        cin >> u >> v;                      
        adj[u].push_back(v);                        
        adj[v].push_back(u);
    }

    cout << "BFS Traversal of graph is: ";

    vector<int> ans = BFSTraversal(n, adj);
    for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
