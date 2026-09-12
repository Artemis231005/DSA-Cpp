#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int row,int col, vector<vector<int>> &image, int newColor, vector<vector<int>> &ans, int iniColor, vector<int> deltaRow, vector<int> deltaCol) {
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = newColor;

    // Check neighbours in 4 dir
    for (int i=0; i<4; i++)  {
        int neighRow = row + deltaRow[i];
        int neighCol = col + deltaCol[i];

        if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m && (image[neighRow][neighCol] == iniColor) && ans[neighRow][neighCol] == iniColor) {
            dfs(neighRow, neighCol, image, newColor, ans, iniColor, deltaRow, deltaCol);
        }
    }
}

// TC: O(N*M) + O(N*M*4) (call dfs for all nodes and check neighbous of all nodes) = O(N*M)   Auxilliary SC: O(N*M) (recursion stack space) + O(4) for dir
vector<vector<int>> floodfill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;

    if (iniColor == newColor) {
        return image;
    }

    vector<int> deltaRow = {-1, 0, 1, 0};
    vector<int> deltaCol = {0, 1, 0,-1};
    dfs(sr, sc, image, newColor, ans, iniColor, deltaRow, deltaCol);
    return ans;
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

    int sr, sc, newColor;

    cout << "Enter starting row and column: ";
    cin >> sr >> sc;
    cout << "Enter new color: ";
    cin >> newColor;

    vector<vector<int>> ans = floodfill(grid, sr, sc, newColor);

    cout << "Flood-filled grid: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;   
}