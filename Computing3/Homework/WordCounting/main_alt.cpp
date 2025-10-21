#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // store all words
    const int wordMax = 1000;
    string words[wordMax];

    // store count for each unique word
    int counts[wordMax] = {0};
    int numWords = 0;

    // list of words to ignore
    const int ignoreMax = 20;
    string ignoreWords[ignoreMax] = {
        "the", "a", "an", "and", "or", "but",
        "of", "to", "in", "on", "for"};

    // scan words
    string aWord;
    cout << "Please enter a paragraph (EOF with ctrl+D / ctrl+Z): ";

    while (cin >> aWord)
    {
        // convert to lowercase to compare the word to see if it matches the list
        for (int i = 0; i < aWord.length(); i++)
        {
            aWord[i] = tolower(aWord[i]);
        }

        // check to see if we need to ignore the current word
        bool isIgnored = false;
        for (int i = 0; i < ignoreMax; i++)
        {
            if (aWord == ignoreWords[i])
            {
                isIgnored = true;
                break;
            }
        }
        if (isIgnored)
            continue;

        // check if the word already exists
        bool found = false;
        for (int i = 0; i < numWords; i++)
        {
            if (words[i] == aWord)
            {
                // if the word exists already increment the amount
                counts[i]++;
                found = true;
                break;
            }
        }

        // if new unique word, add it
        if (!found)
        {
            if (numWords < wordMax)
            {
                // when adding the word set the count to one
                words[numWords] = aWord;
                counts[numWords] = 1;
                numWords++;
            }
            else
            {
                cout << "Reached maximum number of words!" << endl;
                break;
            }
        }
    }

    // output all words and their counts
    cout << "\nWord counts (excluding common words):\n";
    for (int i = 0; i < numWords; i++)
    {
        cout << words[i] << " : " << counts[i] << endl;
    }

    return 0;
}
