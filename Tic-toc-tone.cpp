#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

// Display board
void showBoard() {
    cout << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "---+---+---" << endl;
    }
    cout << endl;
}

// Check win
bool checkWin(char p) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;
        if(board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return true;
    }
    if(board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;
    if(board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Computer move (basic AI)
void computerMove() {
    // Try to win
    for(int i = 0; i < 9; i++) {
        int r = i / 3;
        int c = i % 3;
        if(board[r][c] != 'X' && board[r][c] != 'O') {
            char temp = board[r][c];
            board[r][c] = 'O';
            if(checkWin('O')) return;
            board[r][c] = temp;
        }
    }

    // Block player win
    for(int i = 0; i < 9; i++) {
        int r = i / 3;
        int c = i % 3;
        if(board[r][c] != 'X' && board[r][c] != 'O') {
            char temp = board[r][c];
            board[r][c] = 'X';
            if(checkWin('X')) {
                board[r][c] = 'O';
                return;
            }
            board[r][c] = temp;
        }
    }

    // Take first available spot
    for(int i = 0; i < 9; i++) {
        int r = i / 3;
        int c = i % 3;
        if(board[r][c] != 'X' && board[r][c] != 'O') {
            board[r][c] = 'O';
            return;
        }
    }
}

int main() {
    int move;

    cout << "===== TIC TAC TOE =====" << endl;
    cout << "Player: X  |  Computer: O\n";

    while(true) {
        showBoard();
        cout << "Enter your move (1-9): ";
        cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if(move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = 'X';

        if(checkWin('X')) {
            showBoard();
            cout << "You win!\n";
            break;
        }

        if(checkDraw()) {
            showBoard();
            cout << "Game Draw!\n";
            break;
        }

        computerMove();

        if(checkWin('O')) {
            showBoard();
            cout << "Computer wins!\n";
            break;
        }

        if(checkDraw()) {
            showBoard();
            cout << "Game Draw!\n";
            break;
        }
    }

    return 0;
}
