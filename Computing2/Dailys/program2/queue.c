/*
    Program: queue.c
    Author: AJ Audet
    Date: 3.1.25
    Time spent: 4 hours, making queues w/ linked list is kinda hard but like kinda easy if you treat it like how we did stacks
    Purpose: The purpose of this program is to be the implementation file for creating a queue using linked lists, and to then test the data using the UVA Online Judge for
              problem 11034
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

typedef struct queue /* known type */
{
    Node *front;
    Node *end;
} Queue;

/* hidden functions makes it easier for me l8r on */
Node *create_node(int data);
int get_size(Node* head); 

QUEUE queue_init_def(void)
{
    Queue *pQ = (Queue *)malloc(sizeof(Queue));
    if (pQ == NULL)
    {
        printf("Failed to allocate space for Queue\n");
        exit(1);
    }
    pQ->front = NULL;
    pQ->end = NULL;
    return (QUEUE)pQ;
}

void queue_print(QUEUE hQ)
{
    /* cast to the known type */
    Queue* pQ = (Queue*)hQ;
    Node* temp;

    /* test if hQ is valid */
    if(hQ == NULL)
    {
        printf("error\n");
        exit(1);
    }

    temp = pQ->front;
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Status queue_enqueue(QUEUE hQ, int data)
{
    /* cast to the known type */
    Queue *pQ = (Queue *)hQ;

    /* create a new node */
    Node *temp = create_node(data);

    /* test if Queue is empty if it is both front and end are the new node*/
    if (queue_is_empty(hQ) == TRUE)
    {
        pQ->front = temp;
        pQ->end = temp;
        return SUCCESS;
    }
    pQ->end->next = temp;
    pQ->end = temp;
    return SUCCESS;
}

int* queue_front(QUEUE hQ, Status *pStatus)
{
    /* cast to the known type */
    Queue *pQ = (Queue *)hQ;
    if (queue_is_empty(hQ) == TRUE)
    {
        if (pStatus == NULL)
        {
            *pStatus = FAILURE;
        }
    }

    if (pStatus != NULL)
    {
        *pStatus = SUCCESS;
    }
    return &pQ->front->data;
}

Status queue_service(QUEUE hQ)
{
    /* cast to the known type */
    Queue *pQ = (Queue *)hQ;
    Node* temp;
    if(queue_is_empty(hQ) == TRUE)
    {
        return FAILURE;
    }

    /* store the front of the queue and move the front to the next node */
    temp = pQ->front;
    pQ->front = pQ->front->next;
    
    /* test if the front is NULL */
    if(pQ->front == NULL)
    {
        pQ->end = NULL;
    }

    /* free up the old front */
    free(temp);
    return SUCCESS;
    
}

int queue_get_size(QUEUE hQ)
{
    /* cast to the known type */
    Queue* pQ = (Queue*)hQ;
    if(hQ != NULL)
    {
        return get_size(pQ->front);
    }

    /* if hQ is NULL we need an error value */
    return -1;
}

Boolean queue_is_empty(QUEUE hQ)
{
    /* cast to the known type */
    Queue *pQ = (Queue *)hQ;

    /* test if both the front and the tail are NULL for an empty list */
    if (pQ->front == NULL && pQ->end == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

void queue_destory(QUEUE *phQ)
{
    /* cast to the known type */
    Queue *pQ = (Queue *)*phQ;

    /* iterate through the list using a temp node and then free the old Queue and set phQ to NULL */
    Node* temp = pQ->front;
    while(temp != NULL)
    {
        pQ->front = pQ->front->next;
        free(temp);
        temp = pQ->front;
    }
    free(pQ);
    *phQ = NULL;
}

Node *create_node(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int get_size(Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
