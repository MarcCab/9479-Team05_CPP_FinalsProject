#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hangman.h"

using namespace std;

// Constructor
HangmanGame::HangmanGame() {
    srand(static_cast<unsigned int>(time(nullptr)));
    secretWord = getRandomWord();
    currentWord = string(secretWord.length(), '_');
    attemptsLeft = MAX_ATTEMPTS;
}

// Method to start the game
void HangmanGame::play() {
    cout << "Welcome to Hangman!" << endl;
    cout << "Category: Fruits" << endl;
    cout << "You have " << attemptsLeft << " attempts to guess the fruit name." << endl;

    while (attemptsLeft > 0) {
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        if (isalpha(guess)) {
            guess = tolower(guess);
            if (alreadyGuessed(guess)) {
                cout << "You've already guessed that letter." << endl;
            } else {
                bool correctGuess = updateCurrentWord(guess);
                if (correctGuess) {
                    cout << "Good guess!" << endl;
                    if (currentWord == secretWord) {
                        cout << "Congratulations! You guessed the word: " << endl;
                        return;
                    }
                } else {
                    cout << "Incorrect guess." << endl;
                    attemptsLeft--;
                }
            }
        } else {
            cout << "Please enter a valid letter." << endl;
        }
    }

    if (attemptsLeft == 0) {
        cout << "You've run out of attempts. The word was: "  << endl;
    }
}
