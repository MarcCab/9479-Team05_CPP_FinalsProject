#include <cstdlib>
#include <ctime>
#include "hangman.h"

using namespace std;

// Constructor
HangmanGame::HangmanGame() {
    srand(static_cast<unsigned int>(time(nullptr)));
    secretWord = getRandomWord();
    currentWord = string(secretWord.length(), '_');
    attemptsLeft = MAX_ATTEMPTS;
}