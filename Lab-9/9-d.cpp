// N-Queens Problem (All Solutions)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> Board;

void print_board(Board board) {
    static int count = 1;
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << board[i][j] << " ";
        cout << endl;
    }
    cout << "Completed " << count++ << endl;
}

bool not_attacked(Board &board, int row, int col) {
    int n = board.size();
    for (int j = 0; j < n; j++) if ((j != col) && (board[row][j] == 1)) return 0;
    for (int i = 0; i < n; i++) if ((i != row) && (board[i][col] == 1)) return 0;
    for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++) if (board[i][j] == 1) return 0;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 1) return 0;
    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) if (board[i][j] == 1) return 0;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) if (board[i][j] == 1) return 0;
    return 1;
}

void n_queens(Board &board, int n, int curr_row) {
    if (curr_row == n) {
        print_board(board);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (not_attacked(board, curr_row, i)) {
            board[curr_row][i] = 1;
            n_queens(board, n, curr_row + 1);
            board[curr_row][i] = 0;
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> row(n, 0);
    Board board(n, row);
    n_queens(board, n, 0);
}
