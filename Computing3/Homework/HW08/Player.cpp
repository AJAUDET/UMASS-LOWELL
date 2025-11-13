#include "Player.hpp"

#include <iostream>
#include <string>
using namespace std;

int HumanPlayer::getGuess() {
    cout << "Enter guess (0-100): ";
    cin >> guess;
    return guess;
}

ComputerPlayer::ComputerPlayer()
{
    srand(static_cast<unsigned>(time(nullptr)));
    low = 0;
    high = 100;
    prevGuess = -1;
}

int ComputerPlayer::getGuess() {
    prevGuess = (low + high) / 2;
    cout << "The computer guesses: " << prevGuess << endl;
    return prevGuess;
}

void ComputerPlayer::feedback(bool tooH, bool tooL) {
    if (tooH)
        high = prevGuess - 1;
    else if (tooL)
        low = prevGuess + 1;
}