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
