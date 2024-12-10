#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hangman.h"

#define MAX_ATTEMPTS 6

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
        displayGameInfo();
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
                        displayGameInfo();
                        cout << "Congratulations! You guessed the word: " << secretWord << endl;
                        return;
                    }
                } else {
                    cout << "Incorrect guess." << endl;
                    attemptsLeft--;
                    drawHangman(attemptsLeft);
                }
            }
        } else {
            cout << "Please enter a valid letter." << endl;
        }
    }

    if (attemptsLeft == 0) {
        displayGameInfo();
        cout << "You've run out of attempts. The word was: " << secretWord << endl;
    }
}

// Private helper methods
string HangmanGame::getRandomWord() {
    vector<string> words = { "apple", "banana", "cherry", "grape", "kiwi" };
    int index = rand() % words.size();
    return words[index];
}

bool HangmanGame::alreadyGuessed(char letter) {
    return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
}

bool HangmanGame::updateCurrentWord(char letter) {
    bool correctGuess = false;
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == letter) {
            currentWord[i] = letter;
            correctGuess = true;
        }
    }
    guessedLetters.push_back(letter);
    return correctGuess;
}

// added method to display game state and hangman drawing
void HangmanGame::displayGameInfo() {
    cout << "Word: " << currentWord << endl;
    cout << "Attempts left: " << attemptsLeft << endl;
    cout << "Guessed letters: ";
    for (char letter : guessedLetters) {
        cout << letter << " ";
    }
    cout << endl;
}

void HangmanGame::drawHangman(int attemptsLeft) {
    // Display the hangman drawing based on the number of attempts left
    if (attemptsLeft == 5) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    } else if (attemptsLeft == 4) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |     |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    } else if (attemptsLeft == 3) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    } else if (attemptsLeft == 2) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    } else if (attemptsLeft == 1) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
        cout << "  |    /" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    } else if (attemptsLeft == 0) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
        cout << "  |    / \\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    }
}
