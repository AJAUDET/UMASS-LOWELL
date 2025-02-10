#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"

struct my_vector // known type
{
    int size;     // number of ints I am currently holdong
    int capacity; // number of ints I can hold without resizing
    int *data;
};
typedef struct my_vector My_vector;

MY_VECTOR my_vector_init_default(void)
{
    My_vector *pVector = (My_vector *)malloc(sizeof(My_vector));
    if (pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = (int *)malloc(sizeof(int) * pVector->capacity);
        if (pVector->data == NULL) // handling the Quasimoto state
        {
            free(pVector);
            return NULL;
        }
    }

    return (MY_VECTOR)pVector;
}

Boolean my_vector_is_empty(MY_VECTOR hVector)
{
    My_vector *pVector = (My_vector *)hVector; // cast to the known type

    return (pVector->size <= 0) ? TRUE : FALSE; // using the ?(turnary operator)
}

Status my_vetcor_push_back(MY_VECTOR hVector, int value)
{
    My_vector *pVector = (My_vector *)hVector; // cast to the known type
    int *temp;
    int i;

    if (pVector->size >= pVector->capacity) // there is not enough room so try to make room
    {
        temp = (int *)malloc(sizeof(int) * 2 * pVector->capacity);
        if (temp == NULL)
        {
            return FAILURE;
        }
        for (i = 0; i < pVector->size; i++)
        {
            temp[i] = pVector->data[i];
        }
        free(pVector->data);
        pVector->data = temp;
        pVector->capacity *= 2;
    }

    pVector->data[pVector->size] = value;
    pVector->size++;
    return SUCCESS;
}

Status my_vector_pop_back(MY_VECTOR hVector)
{
    My_vector *pVector = (My_vector *)hVector; // cast to the known type

    if(my_vector_is_empty(hVector) == TRUE)
    {
        return FAILURE;
    }
    pVector->size--;
    return SUCCESS;
}

int my_vector_get_size(MY_VECTOR hVector)
{
    My_vector *pVector = (My_vector *)hVector; // cast to the known type
    return pVector->size;
}

int my_vector_get_capacity(MY_VECTOR hVector)
{
    My_vector *pVector = (My_vector *)hVector; // cast to the known type
    return pVector->capacity;
}

void my_vector_destroy(MY_VECTOR *phVector)
{
    My_vector *pVector = (My_vector *)*phVector;
    free(pVector->data);
    free(pVector);

    *phVector = NULL;
}