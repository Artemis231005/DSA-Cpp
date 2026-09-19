#include <iostream>
#include <vector>
using namespace std;

// TC: O(N^3)   SC: O(N^2) (since we are using matrix to solve it)
void floydWarshallAlgo(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == -1) {       // -1 is used to denote that no edge exists for that pair of nodes
                matrix[i][j] = 1e9;         // we convert it to a  large value, so that min() will prefer any actual path
            }
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
           for (int j=0; j<n; j++) {
                matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
            } 
        }
    }

    bool negativeCycle = false;
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] < 0) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative cycle exists." << endl;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
}

// If graph is guaranteed to not have any -ve wts, we can also apply djikistra for all nodes
// Avg TC: O(N*ElogV) which is less than O(N^3), so Djikistra for all nodes is better
// Unless, we have a dense graph as our WC ie E=V^2, TC becomes O(V³ log V) Floyd–Warshall is O(V³), so FW is asymptotically better for dense all-pairs shortest paths

int main() {
    int V;
    cout << "Enter number of nodes: ";
    cin >> V;

    vector<vector<int>> matrix(V, vector<int>(V));

    cout << "Enter the adjacency matrix (-1 for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> matrix[i][j];
        }
    }

    floydWarshallAlgo(matrix);

    cout << "\nShortest path matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}