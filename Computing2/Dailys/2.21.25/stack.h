/*
    Program: Daily 7 Assignment: stack.h
    Author: AJ Audet
    Date: 2.25.25
    Time spent: 5 hours
    Purpose: The purpose of this program is to use the UVA Online Judge to check our code before submission
*/
#ifndef STACK_H
#define STACK_H

struct stack; // forward declaration
typedef struct stack Stack;

struct stack
{
    char data;
    Stack *next;
};

// precondition : input of a valid Stack and valid character
// post condition : Stack now has the character on the stack
Stack *stack_push(Stack **pStack, char data);

// precondition : input of a valid Stack and valid char*
// post condition : the top of the stack is removed
Stack *stack_pop(Stack *pStack, char *data);

// precondition : valid Stack is used
// post condition : default is NULL
void stack_init_default(Stack *pStack);

// precondition : valid Stack to read
// post condition : returns a value if the stack is empty or not
int stack_is_empty(Stack *pStack);

// precondition : requires 2 valid characters to compare
// post condition : if the characters behave in the accepted ways it will be a success otherwise it fails
int check_complete(char left, char right);

// precondition : requires a valid string to use for comparison
// post condition : returns a value based on if the inputted parentheses is valid
int compare(char *string);

#endif