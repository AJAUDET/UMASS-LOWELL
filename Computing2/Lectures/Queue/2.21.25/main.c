#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[])
{
    QUEUE hQ;

    hQ = queue_init_default();
    if(hQ == NULL)
    {
        printf("Failed to allocate space for queue object\n");
        exit(1);
    }

    // work


    queue_destroy(&hQ);
    return 0;
}