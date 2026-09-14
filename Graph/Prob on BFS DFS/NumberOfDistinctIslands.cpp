#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0, int col0) {
    int n = grid.size(), m = grid[0].size();
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});

    vector<int> deltaRow = {-1, 0, 1, 0};
    vector<int> deltaCol = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
        int nrow = row + deltaRow[i];
        int ncol = col + deltaCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
            dfs(nrow, ncol, grid, vis, vec, row0, col0);
        }
    }
}

// TC: O(n*m*log(n*m))
// SC: O(n*m) for visited array, recursion stack, island vector and set
int countDistinctIslands(vector<vector<int>> grid) { 
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == 1) {
                vector<pair<int, int>> vec;

                dfs(i, j, grid, vis, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main() {
    int n, m;

    cout << "Enter values of n and m: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter grid values:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter value for [" << i << "][" << j << "]: ";
            cin >> grid[i][j];
        }
    }

    cout << "No of Islands: " << countDistinctIslands(grid);
    return 0;
}