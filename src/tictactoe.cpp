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
    char board[3][3] = { 
                        { ' ', ' ', ' ' }, 
                        { ' ', ' ', ' ' }, 
                        { ' ', ' ', ' ' } 
                       };
    string player1, player2;
    char player = 'X';
    int row, col, turn;

    // Get player names
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Enter Player 1's name (X): ";
    cin >> player1;
    cout << "Enter Player 2's name (O): ";
    cin >> player2;

    cout << "\nLet's start the game!\n";

    for (turn = 0; turn < 9; turn++) {
        displayGrid(board);

        // Display the player's turn with their name
        if (player == 'X') {
            cout << "Player " << player1 << ", enter row (0-2) and column (0-2): ";
        } else {
            cout << "Player " << player2 << ", enter row (0-2) and column (0-2): ";
        }

        while (true) {
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
            } else {
                break;
            }
        }
        board[row][col] = player;

        if (checkWin(board, player)) {
            displayGrid(board);
            cout << "Player " << player << " wins!\n";
            return;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    displayGrid(board);
    cout << "It's a draw!\n";
}

