#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// precondition: fp is valid, size matches buffer
// postcondition: data is read into str, null terminated
// postcondition: return NULL if nothing can be read
char *readString(FILE *fp, char *str, int size);
char *combineName(char *first, char *last, char *name, int size);

int main(int argc, char *argv[])
{
    FILE *fp;
    char fname[] = "names.txt";
    int noc;
    char name[50];
    char lname[50];
    char firstn[50];

    fp = fopen(fname, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s", fname);
        exit(1);
    }

    // read names
    // pattern : try --> test --> do
    // noc = fscanf(fp, "%s", name); // try

    fgets(name, 50, fp); // should check
    printf("%s\n", name);

    printf("Press enter to continue");
    getchar(); // other char functions are fgetc, getc

    // we can use fputc, fputs to write cahracters and strings

    while (readString(fp, firstn, sizeof(firstn))) // test
    {
        if(!readString(fp, lname, sizeof(lname)))
            break;
        printf("%s\n", combineName(firstn,lname,name,sizeof(name))); // do
    }

    fclose(fp);

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

char *combineName(char *first, char *last, char *name, int size)
{
    int i = 0;

    while (first[i] != '\0' && i < size - 1)
    {
        name[i] = first[i];
        i++;
    }

    if (i < size - 1)
    {
        name[i] = ' ';
        i++;
    }

    if (i < size - 1)
    {
        name[i] = last[0];
        i++;
    }

    if (i < size - 1)
    {
        name[i] = '\0';
    }

    return name;
}