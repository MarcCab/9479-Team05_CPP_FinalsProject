#include <iostream>
#include "tictactoe.h"
using namespace std;

void showMainMenu();
int getUserInput();

int main() {
    while (true) {
        showMainMenu();

        switch (getUserInput()) {
            case 1:
                playTicTacToe();
                break;
            case 2:
                cout << "Play Hangman" << endl;
                // TODO: Call Hangman game

            default:
                exit(0);
        }
    }
}

void showMainMenu() {
    cout << "+------------------------+" << endl;
    cout << "|  MINI GAMES MAIN MENU  |" << endl;
    cout << "+------------------------+" << endl;
    cout << "| [1] Tic-Tac-Toe        |" << endl;
    cout << "| [2] Hangman            |" << endl;
    cout << "| [3] Exit               |" << endl;
    cout << "+------------------------+" << endl;
}

int getUserInput() {
    int userInput;

    do {
        cin >> userInput;
    }
    while (userInput < 1 || userInput > 3);

    return userInput;
}
