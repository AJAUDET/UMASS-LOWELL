#include "Game.hpp"
#include "Player.hpp"

#include <ctime>
#include <iostream>
#include <cstdlib>

//////////////////////////////////////
// Global functions given in the project
//////////////////////////////////////
bool checkForWin(int guess, int answer) {
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return true;
    } else if (answer < guess) {
        cout << "Your guess is too high." << endl;
    } else {
        cout << "Your guess is too low." << endl;
    }
    return false;
}

// The play function takes as input two Player objects.
void play(Player &player1, Player &player2) {
    srand(static_cast<unsigned>(time(nullptr)));
    int answer = 0, guess1 = 0;
    answer = (rand() % 100) + 1;
    bool win = false;

    while (!win){
        cout << "Player 1's turn to guess." << endl;
        guess1 = player1.getGuess();
        win = checkForWin(guess1, answer);
        if (win) return;

        if (ComputerPlayer* c1 = dynamic_cast<ComputerPlayer*>(&player1)) {
            c1->feedback(guess1 > answer, guess1 < answer);
        }

        cout << "Player 2's turn to guess." << endl;
        int guess2 = player2.getGuess();
        win = checkForWin(guess2, answer);

        if (ComputerPlayer* c2 = dynamic_cast<ComputerPlayer*>(&player2)) {
            c2->feedback(guess2 > answer, guess2 < answer);
        }

    }
}