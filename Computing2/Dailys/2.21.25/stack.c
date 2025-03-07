/*
    Program: Daily 7 Assignment: stack.c
    Author: AJ Audet
    Date: 2.25.25
    Time spent: 5 hours
    Purpose: The purpose of this program is to use the UVA Online Judge to check our code before submission
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_init_default(Stack *pStack)
{
    pStack = NULL;
}

Stack *stack_push(Stack **pStack, char data)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    if (temp == NULL)
    {
        printf("Failed");
        exit(1);
    }

    temp->data = data;
    temp->next = *pStack;
    *pStack = temp;

    return *pStack;
}

Stack *stack_pop(Stack *pStack, char *data)
{
    Stack *temp = pStack;
    *data = temp->data;
    pStack = pStack->next;

    free(temp);
    return pStack;
}

int stack_is_empty(Stack *pStack)
{
    return pStack == NULL ? 1 : 0;
}

int check_complete(char left, char right)
{
    if (left == '[' && right == ']')
    {
        return 1;
    }
    else if (left == '(' && right == ')')
    {
        return 1;
    }
    else if (left == '{' && right == '}')
    {
        return 1;
    }

    return 0;
}

int compare(char *string)
{
    int i = 0;
    char test_chr;
    Stack *test = NULL;
    stack_init_default(test);

    // test conddition as long as string is valid
    while (string[i])
    {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{')
        {
            stack_push(&test, string[i]);
        }

        if (string[i] == ')' || string[i] == ']' || string[i] == '}')
        {
            if (stack_is_empty(test))
            {
                return 0;
            }
            else
            {
                test = stack_pop(test, &test_chr);
                if (!check_complete(test_chr, string[i]))
                {
                    return 0;
                }
            }
        }

        i++;
    }
    if(test == NULL)
    {
        return 1;
    }
    return 0;
}