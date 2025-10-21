#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct vector
{
    int capacity;
    int size;
    int* data;
};

typedef struct vector Vector;

VECTOR vector_init_def(void)
{
    Vector* pVector = (Vector*)malloc(sizeof(Vector));
    if(pVector != NULL)
    {
        pVector->capacity = 1;
        pVector->size = 0;
        pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
        if(pVector->data == NULL)
        {
            free(pVector);
            return NULL;
        }
    }

    return (VECTOR)pVector;
}

void vector_destroy(VECTOR* phVector)
{
    Vector* pVector = (Vector*)*phVector;
    free(pVector->data);
    free(pVector);

    *phVector = NULL;
}
