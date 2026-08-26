#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC: O(N^2) + O(N) = O(N^2)   SC: O(1)

// TC: O(N * (N-1) / 2) = O(N^2)
void transpose(vector<vector<int>> &vec, int n) {
    for (int i=0; i<n-1; i++) {     // only traversal of right/upper half of matrix is needed   (n-1) and not n as the last elem is part of diagnoal
        for (int j=i+1; j<n; j++) {
            swap(vec[i][j], vec[j][i]);
        }
    }
}

// TC: O(N/2) = O(N)
void reverseRows(vector<vector<int>> &vec, int n) {
    // row is vec[i]
    for (int i=0; i<n; i++) {
        reverse(vec[i].begin(), vec[i].end());
    }
}

void display(vector<vector<int>> vec) {
    for (auto &row : vec) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

// TC: O(N^2)   
int main() {
    int n;
    cout << "Enter number of rows and columns: ";
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    transpose(vec, n);
    reverseRows(vec, n);

    cout << "The 90 degree rotated matrix is: " << endl;
    display(vec);

    return 0;
}
