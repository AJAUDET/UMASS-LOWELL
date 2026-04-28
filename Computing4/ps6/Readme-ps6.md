# PS6: RandWriter

## Contact
Name:  AJ Audet
Section:  204
Time to Complete:



## Changes
I completed this assignment after having no submisison initally for ps6
I am resubmitting for PS6: RandWriter, as I had no submission for this section.

## Description
Explain what the project does.

TextWriter is a program that is designed to use a Markov Model of Natural Language to generate a kgram of order k from a given string input.

### Features
Describe what your major decisions were and why you did things that way.

To keep everything organized I used a std::map<std::string, std::map<char, int>> to track my kgram and the frequencies of characters, alongside a std::set<char> to track the alphabet of my kgram.

To generate random numbers I used std::chrono::system_clock::now().time_since_epoch().count() that was stored in a std::min_std_rand0 variable as a seed value, and then that value was put into a std::uniform_int_distribution so we could generate a random kgram every time the program is executed.

I have a private function called validateKgram that tests the length of the kgram against the order to see if the length matches the order.

### Testing
What tests did you write?  What exceptions did you use?  Does your code pass the tests?

I did not write any tests.

### Lambda
What does your lambda expression do?  What function did you pass it to?

I do not use any lambdas.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

I didn't have any real issues with this project other than starting it.

I learned how iterating through a map of maps works by reading through the "How to loop throgh a map" pdf that was given with the zip file for ps6, it definitely helped out because with it I was able to visualize how iterating though them worked with range based for loops, and with that idea in mind it made coding this project that much easier.

Before Submission to PSXb: As of right now there are no issues with my code and it works as intended.

After Submission to PSXb: The issues come from the Your Tests sections, as they are part of the unit test submission I did not do them, as I was not going to implement the unit tests to begin with and wanted to use my redo for PS6 implementation instead of the Unit Tests.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

    - C++ Set: http://cppreference.com/cpp/header/set
    - C++ Map: https://cppreference.com/cpp/header/map
