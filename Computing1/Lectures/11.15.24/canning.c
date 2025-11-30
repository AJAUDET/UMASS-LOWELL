#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp;
    char fname[] = "items.txt";

    fp = fopen(fname, "r");

    if(fp == NULL)
    {
        printf("Error opening file [%s] Exiting program", fname);
        exit(1);
    }

    int noc, max = 0, min = 0, num_of_caps = 0, num, test;
    char c;

    noc = fscanf(fp, "%d", &num);
    while(noc != EOF)
    {
        if(noc == 1)
        {
            test = num;
            if(test < min)
            {
                min = test;
            }
            else if(test > max)
            {
                max = test;
                min = test;
            }
        }
        else if(noc == 0)
        {
            if((c = fgetc(fp)) != EOF)
            {
                if(isupper(c))
                {
                    num_of_caps++;
                }
            }
        }
       noc = fscanf(fp, "%d", &num); 
    } 

    printf("%d MAX // %d MIN // %d NUMBER OF CAPITAL LETTERS\n", max, min, num_of_caps);

    fclose(fp);
    return 0;
}