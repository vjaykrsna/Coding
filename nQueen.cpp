#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the board
void printBoard(const vector<string>& board) {
    for (const string& row : board) {
        cout << row << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<string>& board, int row, int col, int N) {
    // Check this column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<string>& board, int row, int N) {
    if (row == N) {
        // All queens are placed successfully
        printBoard(board);
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 'Q'; // Place the queen
            foundSolution = solveNQueens(board, row + 1, N) || foundSolution;
            board[row][col] = '.'; // Backtrack
        }
    }

    return foundSolution;
}

int main() {
    int N;
    cout << "Enter the size of the board (N): ";
    cin >> N;

    // Initialize the board
    vector<string> board(N, string(N, '.'));

    if (!solveNQueens(board, 0, N)) {
        cout << "No solution exists for " << N << " queens." << endl;
    }

    return 0;
}
