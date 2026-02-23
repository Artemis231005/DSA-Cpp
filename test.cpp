#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool bfs(int s, int t, vector<vector<int>> &residual,
         vector<int> &parent, int V) {

    vector<bool> visited(V, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                if (v == t)
                    return true;
                q.push(v);
            }
        }
    }
    return false;
}

/* Maximum number of edge-disjoint paths = Max Flow
   (all edges have capacity 1) */
int maxEdgeDisjointPaths(vector<vector<int>> &graph, int s, int t, int V) {
    vector<vector<int>> residual = graph;
    vector<int> parent(V);
    int maxFlow = 0;

    while (bfs(s, t, residual, parent, V)) {
        int pathFlow = INT_MAX;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int V = 6;          
    int s = 0, t = 5;   

    vector<vector<int>> graph = {
        {0,1,1,0,0,0},
        {0,0,1,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,1,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    cout << maxEdgeDisjointPaths(graph, s, t, V);
    return 0;
}