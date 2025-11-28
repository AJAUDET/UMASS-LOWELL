/*
    vector practice starting now
*/

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(int argc, char* argv[])
{
    VECTOR hVector = vector_init_def();

    if(hVector == NULL)
    {
        printf("FATAL ERROR\n");
        exit(1);
    }

    vector_destroy(&hVector);

    return 0;
}