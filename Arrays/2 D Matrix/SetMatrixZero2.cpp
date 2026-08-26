#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeros(vector<vector<int>> &vec) {     // TC: O(2*n*m)   SC: O(n+m)
    int n = vec.size();
    int m = vec[0].size();

    vector<int> row (n, 0);
    vector<int> col (m, 0);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (vec[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (row[i] == 1 || col[j] == 1) {
                vec[i][j] = 0;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> vec(n, vector<int>(m));
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    setMatrixZeros(vec);
    cout << "Resultant matrix of matrix with rows and columns set to 0 for 0 values: " << endl;
    for (auto &row : vec) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}
