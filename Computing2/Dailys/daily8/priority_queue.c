/*
    Author: AJ Audet
    Program: priority_queue.c
    Date: April 10 2024
    Time Spend: 4 hours
    Purpose: Implementation file for priority queues, used to demonstrate understanding of the concept
*/

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

typedef struct
{
    int priority;
    int data;
} Node;

typedef struct
{
    Node *heap;
    int size;
    int capacity;
} Priority_queue;

void swap_node(Node *a, Node *b)
{
    Node temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void fix_up(Priority_queue* pPriority, int index)
{
    // as long as there is an index value
    // and test index of parent against index of child accounting for priority
    while(index > 0 && pPriority->heap[(index - 1) / 2].priority < pPriority->heap[index].priority)
    {
            // swap the nodes 
            // update the parent index value
            swap_node(&pPriority->heap[(index -1) / 2], &pPriority->heap[index]);
            index = (index - 1) / 2;
    }
}

void heapify(Priority_queue *pPrioity, int index)
{
    // track the index for the heaps
    int index_of_largest = index;
    int index_of_left = 2 * index + 1;
    int index_of_right = 2 * index + 2;

    // test if the index of the left / right is smaller than the size of the heap
    // test if the priorty is higher in the left / right subtree

    // test if the left index is in bounds
    if (index_of_left < pPrioity->size)
    {
        // test the priority assigned to each node
        if (pPrioity->heap[index_of_left].priority > pPrioity->heap[index_of_largest].priority)
        {
            index_of_largest = index_of_left;
        }
    }
    // do the same for the right
    if (index_of_right < pPrioity->size)
    {
        // test the priority assigned to each node
        if (pPrioity->heap[index_of_right].priority > pPrioity->heap[index_of_largest].priority)
        {
            index_of_largest = index_of_right;
        }
    }

    // if the index is not the largest swap the nodes
    if(index_of_largest != index)
    {
        swap_node(&pPrioity->heap[index], &pPrioity->heap[index_of_largest]);
        heapify(pPrioity, index_of_largest);
    }
}

PRIORITY_QUEUE priority_queue_init_default(void)
{
    Priority_queue* queue = (Priority_queue*)malloc(sizeof(Priority_queue));

    if(queue != NULL)
    {
        queue->capacity = 10;
        queue->size = 0;
        queue->heap = (Node*)malloc(sizeof(Node) * queue->capacity); // test for quasimoto state
        if(queue->heap == NULL)
        {
            free(queue);
            return NULL;
        }
    }
    return queue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    Priority_queue* pQueue = (Priority_queue*)hQueue;
    // test if the size == capactiy if it is resize
    // use realloc? it should work as it lets us reallocate memory as long as the heap isnt null
    if(pQueue->size == pQueue->capacity)
    {
        // double the capactity
        pQueue->capacity *= 2;

        // reallocate memory to account for the new capacity
        pQueue->heap = (Node*)realloc(pQueue->heap, sizeof(Node) * pQueue->capacity);

        // test if it failed
        if(pQueue->heap == NULL)
        {
            return FAILURE;
        }
    }

    // create a temp variable to store the new node to add
    Node temp;
    temp.priority = priority_level;
    temp.data = data_item;
    //insert the item at the end of the heap
    pQueue->heap[pQueue->size] = temp;
    //fix up
    fix_up(pQueue, pQueue->size);
    //incriment size
    pQueue->size++;

    return SUCCESS;

}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
    // similar to heap remove max from the intro to prio queues (its almost the exact same imo)
    Priority_queue* pQueue = (Priority_queue*)hQueue;

    // test that there is an item to remove
    if(pQueue->size == 0)
    {
        return FAILURE;
    }

    // just gonna pretend the value does not exist anymore
    pQueue->heap[0] = pQueue->heap[pQueue->size - 1];
    pQueue->size--;

    //fix the heap after removal
    heapify(pQueue, 0);
    return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
     Priority_queue* pQueue = (Priority_queue*)hQueue;
    // test if the queue is empty
    if(pQueue->size == 0)
    {
        if(pStatus)
        {
            *pStatus = FAILURE;
        }
        return -1337;
    }

    if(pStatus)
    {
        *pStatus = SUCCESS;
    }
    return pQueue->heap[0].data;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Priority_queue* pQueue = (Priority_queue*)hQueue;
    return (pQueue->size == 0) ? TRUE : FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    Priority_queue* pQueue = (Priority_queue*)*phQueue;

    // free the heap then the queue
    if(pQueue)
    {
        free(pQueue->heap);
        free(pQueue);
        *phQueue = NULL;
    }
}
