#include <iostream>
#include <vector>
using namespace std;

void markRow(vector<vector<int>> &vec, int row, int m) {
    for (int j = 0; j < m; j++) {
        if (vec[row][j] != 0) {
            vec[row][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &vec, int col, int n) {
    for (int i = 0; i < n; i++) {
        if (vec[i][col] != 0) {
            vec[i][col] = -1;
        }
    }
}

// Total TC: O(n*m)*(n+m)+(n*m) = O(n^3) (approx)   SC: O(1)
void setMatrixZeros(vector<vector<int>> &vec) {
    int n = vec.size();
    int m = vec[0].size();

    // convert 1 to -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] == 0) {
                markRow(vec, i, m);
                markCol(vec, j, n);
            }
        }
    }

    // convert -1 to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] == -1) {
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
