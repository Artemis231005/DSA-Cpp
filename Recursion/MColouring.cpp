#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int col, vector<int>& color, vector<vector<int>>& graph, int n) {
    for (int k = 0; k < n; k++) {   // going through adjacent nodes
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int node, vector<int>& color, int m, int n, vector<vector<int>>& graph) {
    if (node == n) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, color, graph, n)) {
            color[node] = c;
            if (solve(node + 1, color, m, n, graph)) {
                return true;
            }
            color[node] = 0;   // backtracking
        }
    }
    return false;
}

bool graphColor(vector<vector<int>>& graph, int m, int n) {
    vector<int> color(n, 0);

    if (solve(0, color, m, n, graph)) {
        cout << "Coloring possible" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
        }
        return true;
    }

    cout << "Coloring not possible" << endl;
    return false;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    graphColor(graph, m, n);
    return 0;
}