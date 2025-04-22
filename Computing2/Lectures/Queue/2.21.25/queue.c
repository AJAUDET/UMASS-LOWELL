#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue // known type
{
    int size;
    int capacity;
    int index_of_front;
    int *data;
};
typedef struct queue Queue;

QUEUE queue_init_default(void)
{
    Queue *pQ = (Queue *)malloc(sizeof(Queue));
    if (pQ != NULL)
    {
        pQ->size = 0;
        pQ->index_of_front = 0;
        pQ->capacity = 10;
        pQ->data = (int *)malloc(sizeof(int) * pQ->capacity);
        if (pQ->data == NULL)
        {
            free(pQ);
            return NULL;
        }
    }
    return pQ;
}

Status queue_insert(QUEUE hQ, int value)
{
    Queue *pQ = (Queue *)hQ;
    int *temp;
    int i;

    if (pQ->size >= pQ->capacity) // if there is not enough room make room
    {
        temp = (int *)malloc(sizeof(int) * pQ->capacity * 2);
        if (temp == NULL)
        {
            return FAILURE;
        }
        for(i = 0; i < pQ->size; i++)
        {
            temp[i] = pQ->data[(pQ->index_of_front + i) % pQ->capacity];
        }
        free(pQ->data);
        pQ->data = temp;

        // start here
    }
}

Boolean queue_is_empty(QUEUE hQ)
{
    Queue *pQ = (Queue *)hQ;
    return (pQ->size <= 0) ? TRUE : FALSE;
}

void queue_destroy(QUEUE *phQ)
{
    Queue *pQ = (Queue *)*phQ;

    free(pQ->data);
    free(pQ);
    *phQ = NULL;
}