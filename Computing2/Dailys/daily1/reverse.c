/*
    Name: AJ Audet
    Program: reverse.c
    Date: 1/22/25
    Purpose: taking a predetermined string and reversing the order of the characters
*/
#include <stdio.h>

char *reverse(char *word);

int main(int argc, char *argv[])
{
    char word[] = "Happy Birthday!";

    printf("%s\n", word);
    reverse(word);
    printf("%s\n", word);
    printf("%s\n", reverse(word));
    printf("%s\n", word);

    return 0;
}

char *reverse(char *word)
{
    // declare variables
    int start = 0;
    int end = 0;
    char temp;

    // find the length of the string
    while (word[end] != '\0')
    {
        end++;
    }
    end--;

    // reverse the string
    while (start < end)
    {
        temp = word[start];
        word[start] = word[end];
        word[end] = temp;

        start++;
        end--;
    }

    // return the changed string
    return word;
}