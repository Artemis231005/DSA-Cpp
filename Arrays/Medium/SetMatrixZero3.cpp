#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeros(vector<vector<int>> &vec) {     // TC: O(2*n*m)   SC: O(1)
    int n = vec.size();
    int m = vec[0].size();
    int col0 = 1;
    // col = matrix[0][...] (first row) 
    // row = matrix[...][0] (first col)

    for (int i = 0; i < n; i++) {
        if (vec[i][0] == 0) {
            col0 = 0;
        }
        for (int j = 1; j < m; j++) {
            if (vec[i][j] == 0) {   
                vec[i][0] = 0;
                vec[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (vec[i][0] == 0 || vec[0][j] == 0) {
                vec[i][j] = 0;
            }
        }
    }

    if (vec[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            vec[0][j] = 0;
        }
    }

    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            vec[i][0] = 0;
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
