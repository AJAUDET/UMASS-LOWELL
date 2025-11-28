#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // store all words
    const int wordMax = 1000;
    string words[wordMax];

    // store count for each unique word
    int counts[wordMax]= {0};
    int numWords = 0;

    // scan words
    string aWord;
    cout << "Please enter a paragraph (EOF with ctrl+D / ctrl+Z): ";

    while (cin >> aWord)
    {
        bool found = false;

        // check if the word is already part of the list
        for (int i = 0; i < numWords; i++)
        {
            if (words[i] == aWord)
            {
                counts[i]++;
                found = true;
                break;
            }
        }

        // if the word is not found, add it 
        if (!found)
        {
            if (numWords < wordMax)
            {
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

    for (int i = 0; i < numWords; i++)
    {
        cout << words[i] << " : " << counts[i] << endl;
    }

    return 0;
}