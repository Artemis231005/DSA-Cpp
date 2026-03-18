#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findSumMST(vector<vector<int>> adj[], int v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(v, 0);

    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) {
            continue;
        }
        vis[node] = 1;
        sum += wt;

        for (auto it: adj[node]) {
            int adjNode = it[0];
            int eWt = it[1];
            if (!vis[adjNode]) {
                pq.push({eWt, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int v, E;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> E;

    vector<vector<int>> adj[100];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    int result = findSumMST(adj, v);
    cout << "Sum of MST = " << result;
    return 0;
}