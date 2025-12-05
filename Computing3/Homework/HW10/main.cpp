/***********************************************
Author: AJ Audet
Date: 12/4/2025
Purpose: generating permutations from an input of characters, ints or strings
Time Spent: 1 hour
***********************************************/
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
Date: 12/4/25
Name: AJ Audet
*/

#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

list<list<string>> generate_permutations(const list<string>& inputList) {
    list<list<string>> result;
    if (inputList.empty()) {
        result.push_back(list<string>());
        return result;
    }

    string item = inputList.front();
    list<string> sublist = inputList;
    sublist.pop_front();
    list<list<string>> subPermutations = generate_permutations(sublist);

    for (const auto& perm : subPermutations) {
        size_t n = perm.size();
        for (size_t pos = 0; pos <= n; ++pos) {
            list<string> newPerm;
            auto it = perm.begin();
            for (size_t k = 0; k < pos && it != perm.end(); ++k, ++it) {
                newPerm.push_back(*it);
            }
            newPerm.push_back(item);
            for (; it != perm.end(); ++it) {
                newPerm.push_back(*it);
            }
            result.push_back(newPerm);
        }
    }

    return result;
}

void print_permutations(const list<list<string>>& permutations) {
    int i = 1;
    cout << "Permutations are:" << endl;
    for (const auto& perm : permutations) {
        cout << i << ". ";
        for (const auto& item : perm) {
            cout << item << " ";
        }
        cout << endl;
        i++;
    }
}

int main(int argc, char *argv[]) {
    list<string> inputList;
    string aLine, aString;
    // read in strings from stdin
    cout << "Enter strings, separated by a space:";
    getline(cin, aLine);  // read a line from keyboard
    istringstream iss(aLine);  // convert aLine to an istringstream obj
    // parse each string
    while (iss >> aString) {
    inputList.push_back(aString);
    }
    auto permutations = generate_permutations(inputList);
    // print permutations to stdout
    print_permutations(permutations);
    return 0;
}
