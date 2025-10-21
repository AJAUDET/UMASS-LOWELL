/*
    Author: AJ Audet
    Date: 10/15/2025
    Purpose: utilizing the STL tools we learned in class
    Time Spent: 2 hours, 1 coding 1 debugging
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
Date:   10/15/2025
Name:   AJ Audet
*/

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream inFile;
    string movie;
    int rating;
    double ave;

    // map<movie_name, pair<rating, count>>
    map<string, pair<int, int>> storedMovies;

    if (argc < 2)
    {
        cerr << "Incorrect usage format missing argument(s)";
        return -1337;
    }

    inFile.open(argv[1]);
    if (!inFile)
    {
        cerr << "Error opening file";
        return -1337;
    }

    // get the number of entries
    int entries;
    inFile >> entries;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    // read the full line, store the movie name and rating
    for (int i = 0; i < entries; i++)
    {
        // check to see if we can read a line
        if (!(getline(inFile, movie))) break;

        // check to see if we can read the rating after the movie name
        if (!(inFile >> rating)) break;

        // ignore the next line character if the next line is not EOF
        if (!inFile.eof())
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        // store the rating to the movie name
        // incriment the count of how many times that rating appears
        storedMovies[movie].first += rating;
        storedMovies[movie].second += 1;
    }

    if (storedMovies.empty())
    {
        cerr << "There were no movies found" << endl;
        return -1337;
    }

    // store into a multimap to sort
    multimap<int, string, greater<int>> sortedMovies;
    for (auto movie : storedMovies)
    {
        sortedMovies.insert({movie.second.second, movie.first});
    }

    // output the movies and their average rating
    for (auto output : sortedMovies)
    {
        movie = output.second;
        // access the original stored movies, and calculate the average
        ave = static_cast<double>(storedMovies[movie].first) /
        storedMovies[movie].second;
        cout << movie << ":\t" << storedMovies[movie].second << " reviews, ";
        cout << "average of " << setprecision(2) << ave << " / 5" << endl;
    }

    inFile.close();
    return 0;
}
