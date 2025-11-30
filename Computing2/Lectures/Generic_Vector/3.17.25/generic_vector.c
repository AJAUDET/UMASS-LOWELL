#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

struct generic_vector
{
    int size;
    int capacity;
    ITEM *data;
    ITEM (*fp_init_copy)(ITEM hItem);
    void (*fp_destroy)(ITEM *phItem);
};
typedef struct generic_vector Generic_vector;

GENERIC_VECTOR generic_vector_init_default(ITEM (*fp_init_copy)(ITEM hItem), void (*fp_destroy)(ITEM *phItem))
{
    Generic_vector *pVector = malloc(sizeof(Generic_vector));
    if (pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->fp_init_copy = fp_init_copy;
        pVector->fp_destroy = fp_destroy;
        pVector->data = malloc(sizeof(ITEM) * pVector->capacity);
        if (pVector->data == NULL)
        {
            free(pVector);
            return NULL;
        }
    }
    return pVector;
}

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM value)
{
    Generic_vector *pVector = (Generic_vector *)hVector;
    int i;
    ITEM *temp;

    // start here
    if (pVector->size >= pVector->capacity) // if theres not enough room make room
    {
        temp = (ITEM *)malloc(sizeof(ITEM) * pVector->capacity * 2);
        if (temp == NULL)
        {
            return FAILURE;
        }

        // shallow copy
        for (i = 0; i < pVector->size; i++)
        {
            temp[i] = pVector->data[i];
        }
        pVector->capacity *= 2;
        free(pVector->data);
        pVector->data = temp;
    }

    pVector->data[pVector->size] = pVector->fp_init_copy(value);
    pVector->size++;
    return SUCCESS;
}

ITEM *generic_vector_at(GENERIC_VECTOR hVector, int index)
{
    Generic_vector *pVector = (Generic_vector *)hVector;
    
    if(index < 0 || index >= pVector->size)
    {
        return NULL;
    }

    return pVector->data + index;
}

Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{
    Generic_vector *pVector = (Generic_vector *)hVector;

    if (generic_vector_is_empty(hVector))
    {
        return FAILURE;
    }

    pVector->fp_destroy(pVector->data + pVector->size - 1);
    pVector->size--;
    return SUCCESS;
}

int generic_vector_get_size(GENERIC_VECTOR hVector)
{
    Generic_vector *pVector = (Generic_vector *)hVector;
    return pVector->size;
}

int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
    Generic_vector *pVector = (Generic_vector *)hVector;
    return pVector->capacity;
}

Boolean generic_vector_is_empty(GENERIC_VECTOR hVector)
{
    Generic_vector *pVector = (Generic_vector *)hVector;
    return (pVector->size <= 0) ? TRUE : FALSE;
}

void generic_vector_destroy(GENERIC_VECTOR *phVector)
{
    Generic_vector *pVector = (Generic_vector *)*phVector;
    int i;

    for (i = 0; i < pVector->size; i++)
    {
        pVector->fp_destroy(pVector->data + i);
    }
    free(pVector->data);
    free(pVector);
    *phVector = NULL;
}
