/*
    VECTORS-- code copied over from 1.29.25
*/
#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"

int main(int argc, char* argv[])
{
    MY_VECTOR hVector;
    int i;

    hVector = my_vector_init_default();
    if(hVector == NULL)
    {
        printf("Failed to allocate space for vector object\n");
        exit(1);
    }

    // work


    for(i = 0; i < 1000; i++)
    {
        if(my_vetcor_push_back(hVector, i) == FAILURE)
        {
            printf("Failed to push_back %d\n", i);
            exit(1);
        }
        else
        {
            printf("%d/%d\n", my_vector_get_size(hVector), my_vector_get_capacity(hVector));
        }
    }

    if(my_vector_is_empty(hVector) == TRUE)
        printf("The vector is empty\n");
    else
        printf("The vector is not empty\n");

    my_vector_destroy(&hVector);
    return 0;
}