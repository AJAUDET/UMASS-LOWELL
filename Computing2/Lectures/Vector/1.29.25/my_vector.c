#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"

struct my_vector // known type
{
    int size; // number of ints i am currently holdong
    int capacity; // number of ints i can hold without resizing
    int* data;
};
typedef struct my_vector My_vector;

MY_VECTOR my_vector_init_default(void)
{
    My_vector* pVector = (My_vector*)malloc(sizeof(My_vector));
    if(pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
        if(pVector->data == NULL) // handling the Quasimoto effect
        {
            free(pVector);
            return NULL;
        }
    }

    return (MY_VECTOR)pVector;
}

void my_vector_destroy(MY_VECTOR* phVector)
{
    My_vector* pVector = (My_vector*)*phVector;
    free(pVector->data);
    free(pVector);

    *phVector = NULL;
}