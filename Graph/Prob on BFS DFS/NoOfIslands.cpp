#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse neighbours and mark them if it is part of island
        for (int deltarow=-1; deltarow<=1; deltarow++) {
            for (int deltacol=-1; deltacol<=1; deltacol++) {
                int neigbourRow = row + deltarow;
                int neighbourCol = col + deltacol;

                if (neigbourRow >= 0 && neigbourRow < n && neighbourCol >= 0 && neighbourCol < m && grid[neigbourRow][neighbourCol] == '1'
                    && !vis[neigbourRow][neighbourCol]) {
                        vis[neigbourRow][neighbourCol] = 1;
                        q.push({neigbourRow, neighbourCol});
                }
            }
        }
    }
}

// TC: O(N*M) for traversing the grid.
// Each cell is visited at most once, and for each visited cell, we check 9 positions (8 neighbours + the cell itself).
// Therefore, TC = O(N*M).

// SC: O(N*M) for the visited array + O(N*M) for the queue in the worst case.
// Therefore, SC = O(N*M).
int noOfIslands(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int counter = 0;

    for (int row=0; row<n; row++) {
        for (int col=0; col<n; col++) {
            if (!vis[row][col] && grid[row][col] == '1') {
                counter++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return counter;
}

int main() {
    int n, m;
    cout << "Enter values of n and m: ";
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter grid values:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter value for [" << i << "][" << j << "]: ";
            cin >> grid[i][j];
        }
    }

    cout << "No of Islands: " << noOfIslands(grid);

    return 0;   
}