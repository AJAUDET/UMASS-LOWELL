/*
    Author: AJ Audet
    Date: Nov. 16, 2024
    Purpose: merging data from 2 different files to an output file
    Sources of Help: Instruction Sheet
    Time Spent: 30 mins
*/

#include <stdio.h>
#include <stdlib.h>

void mergeTwoFiles(FILE* f1, FILE* f2, FILE* outfile);

int main(void)
{
    // declare file pointers
    FILE* sfile1;
    FILE* sfile2;
    FILE* outfile;

    // define source files and output files
    char fsource1[] = "numbers1.txt";
    char fsource2[] = "numbers2.txt";
    char outFile[] = "outputFile.txt";

    // open all files and test if they opened
    sfile1 = fopen(fsource1, "r");
    if(sfile1 == NULL)
        fprintf(stderr, "ERROR opening file [%s] Exiting", fsource1);

    sfile2 = fopen(fsource2, "r");
    if(sfile2 == NULL)
        fprintf(stderr, "ERROR opening file [%s] Exiting", fsource2);

    outfile = fopen(outFile, "w");
    if(outfile == NULL)
        fprintf(stderr, "ERROR opening file [%s] Exiting", outFile);

    mergeTwoFiles(sfile1, sfile2, outfile);

    // close the files to redistrubute file resources
    fclose(sfile1);
    fclose(sfile2);
    fclose(outfile);

    return 0;
}

// precondition: all files are valid and are in read mode
// postcondition: data in the output file is from lowest to highest based off of current line
//                  that has been read
void mergeTwoFiles(FILE* f1, FILE* f2, FILE* outfile)
{
    int noc1, noc2, val1, val2;

    noc1 = fscanf(f1, "%d", &val1);
    noc2 = fscanf(f2, "%d", &val2);

    while(noc1 != EOF && noc2 != EOF)
    {
        if(val1 <= val2)
        {
            fprintf(outfile, "%d\n", val1);
            noc1 = fscanf(f1, "%d", &val1);
        }
        else
        {
            fprintf(outfile, "%d\n", val2);
            noc2 = fscanf(f2,"%d", &val2);
        }
    }
    
    if(noc1 == EOF)
    {
        while(noc2 != EOF)
        {
            fprintf(outfile, "%d\n", val2);
            noc2 = fscanf(f2, "%d", &val2);
        }
    }

    if(noc2 == EOF)
    {
        while(noc1 != EOF)
        {
            fprintf(outfile, "%d\n", val1);
            noc1 = fscanf(f1, "%d", &val1);
        }
    }

}