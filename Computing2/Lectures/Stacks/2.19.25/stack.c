#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node;
typedef struct node Node;

struct node
{
    int value;
    Node *next;
};

struct stack // known type
{
    Node *head;
};

typedef struct stack Stack;

STACK stack_init_default(void)
{
    Stack *pStack = (Stack *)malloc(sizeof(Stack));
    if (pStack != NULL)
    {
        pStack->head = NULL;
    }
    return pStack;
}

Status stack_push(STACK hStack, int value)
{
    Stack *pStack = (Stack *)hStack;
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Failed to allocate space for Node");
        return FAILURE;
    }
    temp->next = pStack->head;
    temp->value = value;
    pStack->head = temp;
    return SUCCESS;
}

Status stack_pop(STACK hStack)
{
    Stack *pStack = (Stack *)hStack;
    Node *temp;
    if (stack_is_empty(hStack))
    {
        return FAILURE;
    }

    temp = pStack->head;
    pStack->head = pStack->head->next;
    free(temp);
    return SUCCESS;
}

int stack_top(STACK hStack, Status *pStatus)
{
    Stack *pStack = (Stack *)hStack;
    if (stack_is_empty(hStack))
    {
        if (pStatus != NULL)
        {
            *pStatus = FAILURE;
        }
        return -1337; // leet speak reference hell yeah
    }

    if (pStatus != NULL)
    {
        *pStatus = SUCCESS;
    }
    return pStack->head->value;
}

Boolean stack_is_empty(STACK hStack)
{
    Stack *pStack = (Stack *)hStack;

    return (pStack->head == NULL) ? TRUE : FALSE;
}

void stack_destroy(STACK *phStack)
{
    Stack *pStack = (Stack *)*phStack;
    Node *temp;
    while (pStack->head != NULL)
    {
        temp = pStack->head;
        pStack->head = pStack->head->next;
        free(temp);
    }
    free(pStack);
    *phStack = NULL;
}