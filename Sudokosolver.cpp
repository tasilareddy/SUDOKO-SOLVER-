#include <bits/stdc++.h>
using namespace std;

int recursiveCalls = 0;  // Counter for recursive calls

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
        if (board[row][i] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    recursiveCalls++;  // Increment the counter
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;

                        if (solveSudoku(board)) return true;
                        else board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    
    solveSudoku(board);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "Number of recursive calls: " << recursiveCalls << endl;  // Print the number of recursive calls
    
    return 0;
}
