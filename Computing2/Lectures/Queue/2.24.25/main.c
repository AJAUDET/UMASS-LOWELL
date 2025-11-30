#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[])
{
    QUEUE hQ;
    int i;

    hQ = queue_init_default();
    if(hQ == NULL)
    {
        printf("Failed to allocate space for queue object\n");
        exit(1);
    }

    // work

    for(i = 0; i < 100; i++)
    {
        if(queue_insert(hQ, i) == FAILURE)
        {
            printf("Failed to insert value %d", i);
            exit(1);
        }
    }

    while(queue_is_empty(hQ) == FALSE)
    {
        printf("Front is %d\n", queue_front(hQ, NULL));
        queue_service(hQ);
    }

    queue_destroy(&hQ);
    return 0;
}