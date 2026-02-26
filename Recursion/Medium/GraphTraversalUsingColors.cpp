#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 0: white (not visited yet), 1: gray (discovered but neighbors not fully explored), 2: black (completely explored)
void BFS(int start, vector<vector<int>>& adj, int n) {
    vector<int> color(n, 0);   
    queue<int> q;

    color[start] = 1;   
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u]) {
            if (color[v] == 0) {  
                color[v] = 1;      
                q.push(v);
            }
        }
        color[u] = 2;   
    }
    cout << endl;
}

void DFSHelper(int u, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1;   
    cout << u << " ";

    for (int v : adj[u]) {
        if (color[v] == 0) {   
            DFSHelper(v, adj, color);
        }
    }
    color[u] = 2;  
}

void DFS(int start, vector<vector<int>>& adj, int n) {
    vector<int> color(n, 0);
    cout << "DFS Traversal: ";
    DFSHelper(start, adj, color);
    cout << endl;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(start, adj, n);
    DFS(start, adj, n);
    return 0;
}