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
Date: 9/9/25
Name: AJ Audet
*/

/***********************************************
Author: AJ Audet
Date: September 9 2025
Purpose: Creating a guessing game that takes any input from 1-1000, a number of guesses from 1-10, and provides
feedback based off of higher than the value or lower
Sources of Help: <Please list any sources that you used for help: tutors, websites, lab assistants, etc.>
Time Spent: 30 mins coding, more bc of error checking
***********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

const int MAX_NUMBER = 999;
const int MIN_NUMBER = 1;
const int MAX_GUESS = 10;
const int MIN_GUESS = 1;

void get_min_num(int &min);
void get_max_num(int &max, int min);
void get_guess(int &guess);

void play_again(int &guesses, char &replay);
void play_game(int minimum, int maximum, int &guesses, int number);

int main(void)
{
    srand(time(NULL));
    int minimum = 0, maximum = 0, guesses = 0, rand_number = 0;
    int user_guess;
    char replay = 'y';
    int used_guesses;

    get_min_num(minimum);
    get_max_num(maximum, minimum);
    get_guess(guesses);

    while (replay == 'y')
    {
        int correct_guesses = 0;
        rand_number = (rand() % maximum) + 1;
        while (rand_number < minimum)
        {
            rand_number = (rand() % maximum) + 1;
        }
        cout << "I have a number between " << minimum;
        cout << " and " << maximum << ". Can you guess my number? " << endl;
        cout << "Please enter your first guess. " << endl;
        cout << "? " << endl;

        for (used_guesses = 0; used_guesses < guesses; used_guesses++)
        {
            cin >> user_guess;
            if (user_guess != rand_number)
            {
                if (user_guess > rand_number)
                {
                    cout << "Too high, Try again. " << endl;
					cout << "? " << endl;
                }
                if (user_guess < rand_number)
                {
                    cout << "Too low, Try again. " << endl;
					cout << "? " << endl;
                }
            } else {
                cout << "Victory." << endl;
                correct_guesses = 1;
            }
            if (correct_guesses == 1)
            {
                used_guesses = guesses + 1;
            }
        }
        if (correct_guesses == 0)
        {
            cout << "Defeat." << endl;
            cout << "The number was " << rand_number << endl;
        }

        cout << "Would you like to play again? (y or n)? " << endl;
		cin >> replay;
		while (replay != 'y' && replay != 'n') {
			cout << "Invalid, please enter y or n ";
			cin >> replay;
		}
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}

void get_min_num(int &min)
{
    do
    {
        cout << "Please enter the minimum number, a positive integer: ";
        cin >> min;
    } while (min < MIN_NUMBER || min >= MAX_NUMBER);
}

void get_max_num(int &max, int minimum)
{
    do
    {
        cout << "Please enter the maximum number, which is greater ";
        cout << "than the minimum and less than 1000: ";
        cin >> max;
    } while (max < MIN_NUMBER || max > MAX_NUMBER || minimum >= max);
}

void get_guess(int &guess)
{
    do
    {
        cout << "Enter how many guesses you would like (1-10): ";
        cin >> guess;
    } while (guess < MIN_GUESS || guess > MAX_GUESS);
}
