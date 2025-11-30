/*
    VECTORS
*/
#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"

int main(int argc, char* argv[])
{
    MY_VECTOR hVector;

    hVector = my_vector_init_default();
    if(hVector == NULL)
    {
        printf("Failed to allocate space for vector object\n");
        exit(1);
    }

    // work

    my_vector_destroy(&hVector);
    return 0;
}