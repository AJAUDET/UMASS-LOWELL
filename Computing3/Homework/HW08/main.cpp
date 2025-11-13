/*
    Author: AJ Audet
    Date: 11/12/2025
    Purpose: creating a better number guessing game
    Time Spent: 2 hours
*/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University's Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date:   11/12/2025
Name:   AJ Audet
*/

#include "Player.hpp"
#include "Game.hpp"

#include <iostream>
using std::cout,
    std::endl;

int main(void) {
    srand(static_cast<unsigned>(time(nullptr)));
    cout << "Welcome to the Ultimate Guessing Game!" << endl;
    HumanPlayer human;
    ComputerPlayer computer;
    play(human, computer);
    return 0;
}
