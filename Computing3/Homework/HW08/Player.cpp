#include "Player.hpp"
#include <iostream>

int HumanPlayer::getGuess() {
    std::cin >> guess;
    return guess;
}

ComputerPlayer::ComputerPlayer() {
    low = 0;
    high = 100;
    prevGuess = -1;
}

int ComputerPlayer::getGuess() {
    prevGuess = (low + high) / 2;
    std::cout << "The computer guesses: " << prevGuess << '\n';
    return prevGuess;
}

void ComputerPlayer::feedback(bool tooH, bool tooL) {
    if (tooH)
        high = prevGuess - 1;
    else if (tooL)
        low = prevGuess + 1;
}
