#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

ITEM integer_init_copy(ITEM hItem);

void integer_destroy(ITEM *phItem);

int main(int argc, char *argv[])
{

    GENERIC_VECTOR hVector;
    ITEM (*fp_init_copy)(ITEM hItem);
    void (*fp_destroy)(ITEM *phItem);
    int i;

    hVector = generic_vector_init_default(integer_init_copy, integer_destroy);

    if (hVector == NULL)
    {
        printf("Failed to allocate space for Generic Vector\n");
        exit(1);
    }

    printf("%d/%d\n", generic_vector_get_size(hVector), generic_vector_get_capacity(hVector));
    if (generic_vector_is_empty(hVector) == TRUE)
    {
        printf("woot\n");
    }

    for (i = 0; i < 10; i++)
    {
        if (generic_vector_push_back(hVector, &i) == FAILURE)
        {
            printf("Failed to insert %d", i);
            exit(1);
        }
    }

    *((int*)*(generic_vector_at(hVector, 4))) = 42;

    for(i = 0; i < generic_vector_get_size(hVector); i++)
    {
        printf("%d\n", *((int*)*(generic_vector_at(hVector, i))));
    }

    /*
    while (generic_vector_is_empty(hVector) == FALSE)
    {
        printf("pop -> %d\n", *((int *)*(generic_vector_at(hVector, generic_vector_get_size(hVector) - 1))));
        generic_vector_pop_back(hVector);
    }
    */
    generic_vector_destroy(&hVector);

    return 0;
}

ITEM integer_init_copy(ITEM hItem)
{
    int *pItem = (int *)hItem;
    int *pInt = (int *)malloc(sizeof(int));
    if (pInt != NULL)
    {
        *pInt = *pItem;
    }

    return pInt;
}

void integer_destroy(ITEM *phItem)
{
    ITEM *pItem = (ITEM *)phItem;
    free(pItem);
    phItem = NULL;
}
