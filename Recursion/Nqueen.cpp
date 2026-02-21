#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) {
    // need to check only in 3 direction: left upper diagonal, left and left lower diagnol
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col>=0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while(col >= 0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        col--;
    }

    col = dupcol;
    row = duprow;
    while(row<n && col>=0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';      // backtracking
        }
    }
}

// TC: O(N!)     SC: O(N²) (board + recursion stack)
// vector<vector> as we want all possible configurations of chessboard
vector<vector<string>> solveNqueens (int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');                 // putting empty char on all cells

    for (int i=0; i<n; i++) {
        board[i] = s;
    }

    solve(0, board, ans, n);
    return ans;
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    vector<vector<string>> result = solveNqueens(n);

    for (auto& board : result) {
        for (auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}