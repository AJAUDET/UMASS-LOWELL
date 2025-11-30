#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic_vector.h"


GENERIC_VECTOR generic_vector_init_default(Status(*item_assignment)(ITEM* pLeft, ITEM Right), void(*item_destroy)(ITEM* ppItem)) 
{
    My_vector* pVector;
    int i;
    pVector = (My_vector*)malloc(sizeof(My_vector));
    if (pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = (ITEM*)malloc(sizeof(ITEM)*pVector->capacity);
        if (pVector->data == NULL)
        {
            free(pVector);
            pVector = NULL;
        }
        else
        {
            for (i = 0; i < pVector->capacity; i++)
            {
                pVector->data[i] = NULL;
            }
            pVector->item_assignment = item_assignment;
            pVector->item_destroy = item_destroy;
        }
    }
    return pVector;
}

int generic_vector_get_size(GENERIC_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return pVector->size;
}
int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return pVector->capacity;
}

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM item)
{
    My_vector* pVector = (My_vector*)hVector;
    ITEM* pTemp;
    int i;
    //if there is not enough capacity, fix it.
    if (pVector->size >= pVector->capacity)
    {
        pTemp = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity * 2);
        if (pTemp == NULL)
        {
            return FAILURE;
        }
        else
        {
            for (i = 0; i < pVector->size; i++)
            {
                pTemp[i] = pVector->data[i];
            }
            pVector->capacity *= 2;
            //fill the rest with NULL
            for (; i < pVector->capacity; i++)
            {
                pTemp[i] = NULL;
            }
            free(pVector->data);
            pVector->data = pTemp;
        }
    }
    pVector->item_assignment(&(pVector->data[pVector->size]), item);
    pVector->size++;
    return SUCCESS;
}

Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    
    if (pVector->size <= 0)
    {
        return FAILURE;
    }
    pVector->size--;
    if (pVector->data[pVector->size] != NULL)
    {
        pVector->item_destroy(&(pVector->data[pVector->size]));
    }
    
    return SUCCESS;
}

ITEM generic_vector_at(GENERIC_VECTOR hVector, unsigned int index)
{
    My_vector* pVector = (My_vector*)hVector;
    
    if (index >= pVector->size)
    {
        return NULL;
    }
    
    return (pVector->data[index]);
}

Boolean generic_vector_is_empty(GENERIC_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return pVector->size == 0;
}

void generic_vector_destroy(GENERIC_VECTOR* phVector)
{
    My_vector* pVector = (My_vector*)*phVector;
    int i;
    
    for (i = 0; i < pVector->size; i++)
    {
        if (pVector->data[i] != NULL)
        {
            pVector->item_destroy(&(pVector->data[i]));
        }
    }
    free(pVector->data);
    free(pVector);
    
    *phVector = NULL;
    
    return;
}
