#include "Game.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

bool checkForWin(int guess, int answer) {
    if (guess == answer) {
        cout << "You're right! You win!" << endl;
        return true;
    } else if (guess > answer) {
        cout << "Your guess is too high." << endl;
    } else {
        cout << "Your guess is too low." << endl;
    }
    return false;
}

void play(Player &player1, Player &player2) {
    int answer = (rand() % 100) + 1;
    bool win = false;

    while (!win) {
        cout << "Player 1's turn to guess. ";
        int guess1 = player1.getGuess();
        win = checkForWin(guess1, answer);
        if (win) return;

        if (auto* c1 = dynamic_cast<ComputerPlayer*>(&player1))
            c1->feedback(guess1 > answer, guess1 < answer);

        cout << "Player 2's turn to guess: ";
        int guess2 = player2.getGuess();
        win = checkForWin(guess2, answer);

        if (auto* c2 = dynamic_cast<ComputerPlayer*>(&player2))
            c2->feedback(guess2 > answer, guess2 < answer);
    }
}
