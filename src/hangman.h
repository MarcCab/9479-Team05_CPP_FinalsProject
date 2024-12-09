#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

class HangmanGame {
public:
    // Constructor to initialize the game
    HangmanGame();

    // Method to start the game
    void play();

private:
    std::string secretWord;
    std::string currentWord;
    int attemptsLeft;
    std::vector<char> guessedLetters;

    // Helper methods
    std::string getRandomWord();
    bool alreadyGUessed(char letter);
    bool updateCurrentWord(char letter);
    void displayGameInfo();
    void drawHangman(int attemptsLeft);
};

#endif