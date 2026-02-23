#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool isSafe(vector<vector<int>>& maze, vector<vector<int>>& vis, int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && vis[x][y] == 0);
}

bool solveMazeUtil(vector<vector<int>>& maze, vector<vector<int>>& vis, int x, int y, int n, string& path) {
    if (x == n - 1 && y == n - 1) {
        vis[x][y] = 1;
        return true;
    }

    if (isSafe(maze, vis, x, y, n)) {
        vis[x][y] = 1;

        // Down
        if (solveMazeUtil(maze, vis, x + 1, y, n, path)) {
            path.push_back('D');
            return true;
        }

        // Right
        if (solveMazeUtil(maze, vis, x, y + 1, n, path)) {
            path.push_back('R');
            return true;
        }

        // Up
        if (solveMazeUtil(maze, vis, x - 1, y, n, path)){
            path.push_back('U');
            return true;
        }

        // Left
        if (solveMazeUtil(maze, vis, x, y - 1, n, path)) {
            path.push_back('L');
            return true;
        }

        // Backtracking
        vis[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(vector<vector<int>>& maze, int n) {
    vector<vector<int>> vis(n, vector<int>(n, 0));
    string path = "";

    if (!solveMazeUtil(maze, vis, 0, 0, n, path)) {
        cout << "No Solution Found";
        return;
    }

    reverse(path.begin(), path.end());
    cout << "Path: " << path;

    // cout << "Solution: \n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //         cout << vis[i][j] << " ";
    //     cout << endl;
    // }
}

int main() {
    vector<vector<int>> maze = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {1, 1, 1, 1}
    };

    int n = maze.size();
    solveMaze(maze, n);
    return 0;
}