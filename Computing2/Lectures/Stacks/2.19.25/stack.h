#ifndef STACK_H
#define STACK_H
#include "status.h"
typedef void* STACK;

STACK stack_init_default(void);

Status stack_push(STACK hStack, int value);
Status stack_pop(STACK hStack);

int stack_top(STACK hStack, Status *pStatus);

Boolean stack_is_empty(STACK hStack);


void stack_destroy(STACK* phStack);

#endif