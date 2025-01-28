#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct wordscore // 10 bytes
{
    char word[6];
    int score;
};
typedef struct wordscore Wordscore;

char *readString(FILE *fp, char *str, int size);
int hasDoubles(char buffer[], int size);

int main(int argc, char *argv[])
{
    FILE *fp;
    char fname[] = "wordlist.txt";
    int *pAlph;
    int i, j;
    char c;
    char buff[6];
    int score;
    int maxScore = 0;
    int wordCount = 0;

    Wordscore *pW;


    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Error opening file [%s] Exiting\n", fname);
        exit(1);
    }

    pAlph = malloc(26 * sizeof(int));
    if (pAlph == NULL)
    {
        printf("Error allocating memory: Exiting\n");
        exit(1);
    }

    for (i = 0; i < 26; i++)
        pAlph[i] = 0;

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n' || c == ' ')
            wordCount++;
        if (isalpha(c))
            pAlph[c - 'A']++;
    }

    fclose(fp);

    printf("Wordcount is %d\n", wordCount);

    for (i = 0; i < 26; i++)
        printf("%c : %5d\n", i + 'A', pAlph[i]);

    fp = fopen(fname, "r");

    FILE *fp1;

    fp1 = fopen("wordsScored.csv", "w");
    if (fp1 == NULL)
    {
        printf("Error opening file -- Exiting\n");
        exit(1);
    }

    pW = malloc(wordCount * sizeof(Wordscore));
    if (pW == NULL)
    {
        printf("Error allocating memory -- Exiting\n");
        exit(1);
    }

    j = 0;
    while (readString(fp, pW[j].word, 6) != 0)
    {
        pW[j].score = 0;
        for (i = 0; i < 5; i++)
            pW[j].score += pAlph[pW[j].word[i] - 'A'];

        if (pW[j].score > maxScore)
            maxScore = pW[j].score;

        j++;
    }
    printf("Max Score: %d\n", maxScore);

    for (i = 0; i < wordCount; i++)
    {
        if (!hasDoubles(pW[i].word, 6) && pW[i].score > .85 * maxScore)
        {
            printf("%s : %4d\n", pW[i].word, pW[i].score);
            fprintf(fp1, "%s : %5d\n", pW[i].word, pW[i].score);
        }
    }

    free(pW);
    fclose(fp1);
    free(pAlph);
    fclose(fp);

    return 0;
}

int hasDoubles(char buffer[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size - 1; j++)
        {
            if (buffer[i] == buffer[j])
                return 1;
        }
    }
    return 0;
}

char *readString(FILE *fp, char *str, int size)
{
    int noc;
    char c;
    int index = 0;

    noc = fscanf(fp, " %c", &c); // try to read one character, skipping any blanks

    if (noc == EOF)
    {
        return NULL;
    }

    str[0] = c;
    index++;

    noc = fscanf(fp, "%c", &c); // try to read one character

    while (noc == 1 && !isspace(c) && index < size - 1) // test
    {
        str[index] = c; // do
        index++;
        noc = fscanf(fp, "%c", &c); // try to read one character
    }

    if (noc == EOF)
    {
        str[index] = '\0';
    }
    else if (isspace(c))
    {
        ungetc(c, fp);
        str[index] = '\0';
    }
    else if (index >= size - 1)
    {
        ungetc(c, fp);
        str[index] = '\0';
    }

    return str;
}