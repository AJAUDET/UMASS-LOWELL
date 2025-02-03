/*
    Author: AJ Audet
    Course: CCOMP1010, Computing I, Section 302
    Date Started: Nov 22, 2024
    Date Ended: Nov 24, 2024
    Description: This file implements the functionality required by Program 3, to read from one file then output the formated data
                  to another file, then copying over that data into the original file
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void readFromFile(FILE *fin, char firstName[], char lastName[], int quizVals[]);
void writeToFile(FILE *fout, char firstName[], char lastName[], int quizVals[]);

int main(void)
{
    // declare variables for files, i/o, and storage
    FILE *fin;
    FILE *fout;

    char fileName1[] = "quiz.txt";
    char fileName2[] = "average.txt";

    char firstName[20];
    char lastName[20];

    int quizVals[10];
    int count = 0;
    double avg;
    char avgVals[10];

    // open files and validate if they can be opened or failed to
    fin = fopen(fileName1, "r");
    if (fin == NULL)
    {
        printf("Error opening file [%s] Exiting\n", fileName1);
        exit(1);
    }

    fout = fopen(fileName2, "w");
    if (fout == NULL)
    {
        printf("Error opening file [%s] Exiting\n", fileName2);
        exit(1);
    }

    while (!feof(fin))
    {
        // read from input file
        readFromFile(fin, firstName, lastName, quizVals);

        // write to the output file and display average as well
        // use proper column justification to allign values
        writeToFile(fout, firstName, lastName, quizVals);
    }

    // redistribure resources
    fclose(fin);
    fclose(fout);

    // reopen rescources and write the output to the input
    fin = fopen(fileName2, "r");
    if (fin == NULL)
    {
        printf("Error opening file [%s] Exiting\n", fileName2);
        exit(1);
    }

    fout = fopen(fileName1, "w");
    if (fout == NULL)
    {
        printf("Error opening file [%s] Exiting\n", fileName1);
        exit(1);
    }
    while (!feof(fin))
    {
        // read from average.txt
        fscanf(fin, "%s %s", firstName, lastName);
        for (int i = 0; i < 10; i++)
        {
            fscanf(fin, "%d", &quizVals[i]);
        }
        fscanf(fin, "%s", avgVals);

        // write back into quiz.txt
        fprintf(fout, "%-20s %-20s", firstName, lastName);
        for(int i = 0; i < 10; i++)
        {
            fprintf(fout, "%4d", quizVals[i]);
        }
        fprintf(fout, "%6s \n", avgVals);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

// precondition: valid file for input, valid first and last name, valid quiz values
// post condition: everything is stored in the proper variables
void readFromFile(FILE *fin, char firstName[], char lastName[], int quizVals[])
{
    int i;
    // i < 10 because there will be 10 quiz values, if there is a blank assumed 0
    for (i = 0; i < 10; i++)
    {
        quizVals[i] = 0;
    }

    fscanf(fin, "%s %s", firstName, lastName);

    for (i = 0; i < 10; i++)
    {
        fscanf(fin, "%d", &quizVals[i]);
    }
}

// precondition: valid file for output, valid first and last name, valid quiz values
// postconditions: the output file is filled with the correct data in the
//                 way it needs to be formated lname fname 1 2 3 4 5 6 7 8 9 10 avg
void writeToFile(FILE *fout, char firstName[], char lastName[], int quizVals[])
{
    int i, sum = 0;
    double average;

    fprintf(fout, "%-20s %-20s", lastName, firstName);

    for (i = 0; i < 10; i++)
    {
        fprintf(fout, "%4d", quizVals[i]);
        sum += quizVals[i];
    }

    average = sum / 10.0;

    fprintf(fout, "%6.2lf \n", average);
}