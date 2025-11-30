#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum
{
    false,
    true
} bool;

int main(void)
{
    FILE *fp;
    char fname[] = "input.txt";

    int noc, counter = 0;
    double num;
    int min, max;
    char ch;
    bool firstNumberRead = false;

    // not robust
    // max = 0;
    // min = 0;

    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Error opening file [%s] Exiting", fname);
        exit(1);
    }

    noc = fscanf(fp, "%lf", &num);

    while (noc != EOF)
    {
        if (noc == 1)
        {
            if (!firstNumberRead)
            {
                min = (int) num;
                max = (int) num;
                firstNumberRead = true;
            }
            if (num < min)
                min = (int) num;
            if (num > max)
                max = (int) num;
        }
        else
        {
            noc = fscanf(fp, "%c", &ch);
            if (noc == 1)
            {
                if (isupper(ch))
                    counter++;
            }
            else
                break;
        }
        noc = fscanf(fp, "%lf", &num);
    }

    fclose(fp);

    if(firstNumberRead)
        printf("Min [%d], Max [%d], Number of Caps [%d]", min, max, counter);
    else
        printf("No numbers in file [%s], Number of Caps [%d]", fname, counter);
    return 0;
}