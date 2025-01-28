#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // isspace, islower, isupper, toupper,tolower,isdigit, is alpha, ispunct

void copyFile(char* source, char* dest);
void copyFileAndConvertToUpperCase(char* source, char* dest);

int main(int argc, char* argv[])
{
    FILE* fp;
    char fname[] = "numbers.txt";
    char* fname2 = "numbers2.txt";


    fp = fopen(fname2, "w");
    
    if(fp == NULL)
    {
        printf("Could not open file %s - exiting\n", fname2);
        exit(1);
    }

    srand(time(0));

    int r = rand() % 100; 
    printf("Writing file with %d numbers\n", r);
    for(int i = 0; i < r; i++)
    {
        fprintf(fp, "%d\n", i);
    }

    fclose(fp);

    fp = fopen(fname2, "r");
    
    if(fp == NULL)
    {
        printf("Could not open file %s - exiting\n", fname2);
        exit(1);
    }

    int num, noc;


    noc = fscanf(fp, "%d", &num); // try

    while(noc != EOF && noc == 1) // test
    {
        printf("Reading number %d\n", num); // do
        noc = fscanf(fp, "%d", &num); // try
    }

    fclose(fp);

    copyFile(fname2, "numbers_copy.txt");

    if(argc == 3)
        copyFileAndConvertToUpperCase(argv[1], argv[2]);

    return 0;
}

void copyFile(char* source, char* dest)
{
    FILE* fp;
    FILE* fp1;
    fp = fopen(source, "r");
    
    if(fp == NULL)
    {
        printf("Could not open file %s - exiting\n", source);
        exit(1);
    }



    fp1 = fopen(dest, "w");
    
    if(fp1 == NULL)
    {
        printf("Could not open file %s - exiting\n", dest);
        exit(1);
    }

    int noc;
    char c;

    noc = fscanf(fp, "%c", &c); // try
    while(noc != EOF) // test
    {
        fprintf(fp1, "%c",c); // do
        noc = fscanf(fp, "%c", &c); // try
    }

    fclose(fp);
    fclose(fp1);
}

void copyFileAndConvertToUpperCase(char* source, char* dest)
{
    FILE* fp;
    fp = fopen(source, "r");
    
    if(fp == NULL)
    {
        printf("Could not open file %s - exiting\n", source);
        exit(1);
    }


    FILE* fp1;
    fp1 = fopen(dest, "w");
    
    if(fp1 == NULL)
    {
        printf("Could not open file %s - exiting\n", dest);
        exit(1);
    }

    int noc;
    char c;

    noc = fscanf(fp, "%c", &c); // try
    while(noc != EOF) // test
    {
        fprintf(fp1, "%c",toupper(c)); // do
        noc = fscanf(fp, "%c", &c); // try
    }

    fclose(fp);
    fclose(fp1);
}