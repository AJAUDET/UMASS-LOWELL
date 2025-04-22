#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

int main(int argc, char* argv[])
{
    GENERIC_VECTOR hVector;
    hVector = generic_vector_init_default(/*pass in a way to copy and destroy*/);
    if(hVector == NULL)
    {
        printf("error\n");
        exit(1);
    }

    generic_vector_destroy(&hVector);

    return 0;
}