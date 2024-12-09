// TicTacToe Game
#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayGrid(char grid[3][3]) {
    cout << "-------------\n";
    for (int row = 0; row < 3; row++) {
        cout << "| ";
        for (int col = 0; col < 3; col++) {
            cout << grid[row][col] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to play Tic-Tac-Toe
void playTicTacToe() {
    string player1, player2;
    char board[3][3];
    char player;
    bool playAgain;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Enter Player 1's name (X): ";
    cin >> player1;
    cout << "Enter Player 2's name (O): ";
    cin >> player2;

    do {
        // Initialize board
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';

        player = 'X'; // Player X always starts
        int turn, row, col;

        cout << "\nLet's start the game!\n";
        for (turn = 0; turn < 9; turn++) {
            displayGrid(board);
            cout << (player == 'X' ? player1 : player2) 
                 << "'s turn (" << player << "). Enter row (1-3) and column (1-3), separated by a space: ";

            while (true) {
                cin >> row >> col;
                row -= 1;
                col -= 1;

                if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                    cout << "Invalid move. Try again: ";
                } else {
                    break;
                }
            }

            board[row][col] = player;

            if (checkWin(board, player)) {
                displayGrid(board);
                cout << (player == 'X' ? player1 : player2) << " wins!\n";
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        if (turn == 9) {
            displayGrid(board);
            cout << "It's a draw!\n";
        }

        char response;
        cout << "Do you want to play again? (Y/N): ";
        cin >> response;
        playAgain = (response == 'Y' || response == 'y');
    } while (playAgain);

    cout << "Thank you for playing Tic-Tac-Toe!\n";
}

