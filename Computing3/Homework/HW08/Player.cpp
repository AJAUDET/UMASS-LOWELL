#include "Player.hpp"

#include <iostream>
#include <string>
using std::cout,
    std::endl,
    std::cin;

int HumanPlayer::getGuess() {
    cout << "enter guess (0-100): ";
    cin >> guess;
    return guess;
}

ComputerPlayer::ComputerPlayer()
{
    low = 0;
    high = 100;
    prevGuess = -1;
}

int ComputerPlayer::getGuess() {
    prevGuess = (low + high) / 2;
    cout << "the computer guesses: " << prevGuess << '\n';
    return prevGuess;
}

void ComputerPlayer::feedback(bool tooH, bool tooL) {
    if (tooH)
        high = prevGuess - 1;
    else if (tooL)
        low = prevGuess + 1;
}
