#ifndef STACK_H
#define STACK_H

typedef void* STACK;

STACK stack_init_default(void);

void stack_destroy(STACK* phStack);

#endif