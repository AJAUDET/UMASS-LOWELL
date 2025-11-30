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
Date: 9/17/25
Name: AJ Audet
*/
/*
Author: AJ Audet
Date: 9/17/25
Purpose: reads from a file and replaces case sensitive words
Sources of Help: None
Time Spent: 30 mins coding
*/

#include <iostream>
#include <fstream>
using namespace std;

const string def_input_file = "input.txt";

const string love = "love";
const string loves = "loves";
const string dislike = "dislike";
const string dislikes = "dislikes";

int main(int argc, char *argv[]) {
    ifstream f_input;

    string test_word;

    if (argc == 2) {
        string alt_file = argv[1];
        f_input.open(alt_file);
    } else {
        f_input.open(def_input_file);
    }

    if (f_input.fail()) {
        cerr << "Error opening file " << def_input_file << " terminating with exit code 1";
        exit(1);
    }

    while (f_input >> test_word) {
        if (test_word == dislike) {
            test_word = love;
        } else if (test_word == dislikes) {
            test_word = loves;
        }
        cout << test_word << " ";
    }
    cout << endl;

    f_input.close();

    return 0;
}
