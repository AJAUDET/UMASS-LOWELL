#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp;
    int num, sum = 0, noc;
    char fname[] = "testdata25.txt";

    fp = fopen(fname, "r");
    if(fp == NULL)
    {
        printf("Error opening file [%s] Exiting", fname);
        exit(1);
    }

    noc = fscanf(fp, "%d", &num);
    while(noc != EOF)
    {
        sum += num;
        noc = fscanf(fp, "%d", &num);
    }

    fclose(fp);

    printf("The sum of the numbers in [%s] is [%d]\n", fname, sum);

    return 0;
}