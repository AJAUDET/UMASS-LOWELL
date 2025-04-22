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


    for(i = 0; i < 16; i++)
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

    for(i= 0; i < my_vector_get_size(hVector); i++)
    {
        printf("%d\n", *my_vector_at(hVector, i));
    }

    *(my_vector_at(hVector, 4) + 1) = 42;

    if(my_vector_is_empty(hVector) == TRUE)
        printf("The vector is empty\n");
    else
        printf("The vector is not empty\n");

    my_vector_destroy(&hVector);
    return 0;
}