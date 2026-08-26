#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> vec) {
    for (auto &row : vec) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

// TC: O(N^2)   SC: O(N^2)
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

    vector<vector<int>> ans(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans[j][n - 1 - i] = vec[i][j];
        }
    }

    cout << "The 90 degree rotated matrix is: " << endl;
    display(ans);
}
