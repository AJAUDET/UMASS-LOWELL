#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);

// insert ** 
Status queue_insert(QUEUE hQ, int value);

// service
Status queue_service(QUEUE hQ);

// front
int queue_front(QUEUE hQ, Status* pStatus);

// empty **
Boolean queue_is_empty(QUEUE hQ);

void queue_destroy(QUEUE* phQ);

#endif