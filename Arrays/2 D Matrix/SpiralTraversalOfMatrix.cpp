#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &vec) {
    for (int x : vec) {
        cout << x << " ";
  }
}

// TC: O(N*M)   SC: O(N*M)
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
    
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while(top <= bottom && left <= right) {
        // left to right
        for (int i=left; i<=right; i++) {
            ans.push_back(vec[top][i]);
        }
        top++;

        // top to bottom
        for (int i=top; i<=bottom; i++) {
            ans.push_back(vec[i][right]);
        }
        right--;

        if (top <= bottom) {
            // right to left
            for (int i=right; i>=left; i--) {
                ans.push_back(vec[bottom][i]);
            }
            bottom--;
        }

        // we only add ifs after this point as atp both top and bottom ahs chnaged, and not true before it

        if (left <= right) {
            // bottom to top
            for (int i=bottom; i>=top; i--) {
                ans.push_back(vec[i][left]);
            }
            left++;
        }
    }

    display(ans);
    return 0;
}
