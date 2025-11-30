#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int numbers[300000];

    int* pNums;

    numbers[200000] = 22;

    printf("numbers[200000] is %d\n", numbers[200000]);

    pNums = malloc(300000 * sizeof(int));
    if(pNums == NULL)
    {
        printf("Error allocating memory: Exiting\n");
        exit(1);
    }

    pNums[200000] = 44;

    printf("pNums[200000] is %d\n", pNums[200000]);
    free(pNums);

    return 0;
}