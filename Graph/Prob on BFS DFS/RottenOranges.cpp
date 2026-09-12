#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(N*M), since every cell is processed at most once and 4 neighbours are checked
// SC: O(N*M) for the BFS queue in the WC and vis matrix
int rotAllOranges(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q; // (row, col, time)
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int counterFreshOranges = 0;

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == 2) {  // means rotten orange
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            } else {
                vis[i][j] = 0;
            }

            if (grid[i][j] == 1) {
                counterFreshOranges++;
            }
        }
    }

    int totalTime = 0;
    vector<int> deltarow = {-1, 0, 1, 0};
    vector<int> deltacol = {0, 1, 0, -1};
    int counter = 0;
    
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();

        totalTime = max(totalTime, time);

        for (int i=0; i<4; i++) {
            int neighRow = row + deltarow[i];
            int neighCol = col + deltacol[i];

            if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m && vis[neighRow][neighCol] == 0 && grid[neighRow][neighCol] == 1) {
                q.push({{neighRow, neighCol}, time + 1});
                vis[neighRow][neighCol] = 1;
                counter++;
            }
        }
    }

    // check if all good oranges became rotten or not
    if (counter != counterFreshOranges) {
        return -1;
    }

    return totalTime;
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

    int result = rotAllOranges(grid);
    cout << "Minimum time required: " << result << endl;

    return 0;   
}