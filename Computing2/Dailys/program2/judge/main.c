#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* for strcmp */

/* working with cm is easier than m, so setup a conversion factor */
#define CONVERSION .01

enum status
{
    FAILURE,
    SUCCESS
};
typedef enum status Status;

enum boolean
{
    FALSE,
    TRUE
};
typedef enum boolean Boolean;

typedef void *QUEUE;

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
int get_size(Node *head);

QUEUE queue_init_def(void);
Status queue_enqueue(QUEUE hQ, int data);
Status queue_service(QUEUE hQ);
int *queue_front(QUEUE hQ, Status *pStatus);
Boolean queue_is_empty(QUEUE hQ);
int queue_get_size(QUEUE hQ);

void queue_print(QUEUE hQ);

void queue_destory(QUEUE *phQ);

void clearKeyboardBuffer(void);
void run_tests(int tests);
int get_length_and_side(QUEUE left, QUEUE right);
int travel(QUEUE left, QUEUE right, int length);
void load_ferry(QUEUE hQ, int length);

int main(void)
{
    int num_test;

    /* scan for number of tests to use fgets / scanf */
    scanf("%d", &num_test);
    clearKeyboardBuffer();

    run_tests(num_test);

    return 0;
}

void run_tests(int tests)
{
    QUEUE left;
    QUEUE right;
    /* test if there are any tests to run */
    if (tests <= 0)
    {
        printf("No cases entered\n");
        exit(1);
    }

    /* if there is set up variables for the length */
    int length;
    int trips_taken;

    /* test that there is at least 1 case */
    while (tests > 0)
    {
        /* create a queue for the right and left side */
        left = queue_init_def();
        right = queue_init_def();

        if (left == NULL || right == NULL)
        {
            printf("FATAL ERROR -- EXITING\n");
            /* free up the allocated memory for the initialized one*/
            if (left != NULL)
            {
                queue_destory(&left);
            }
            if (right != NULL)
            {
                queue_destory(&right);
            }
            exit(1);
        }

        /*
            now the fun stuff
            get the length of the ferry
        */
        length = get_length_and_side(left, right);

        /* cross the river */
        trips_taken = travel(left, right, length);

        printf("%d\n", trips_taken);

        /* free the queue for the next test */
        queue_destory(&left);
        queue_destory(&right);

        /* incriment the trips taken and decriment the tests */
        tests--;
    }
}

int get_length_and_side(QUEUE left, QUEUE right)
{
    /* create variables to track length, number of cars, car length, and which side of the river the ferry is on*/
    Status status;
    int ferry_len;
    int car_len;
    int num_cars;
    char direction[10];
    int i;

    /* scan for number of cars and ferry length*/
    scanf("%d %d", &ferry_len, &num_cars);

    for (i = 0; i < num_cars; i++)
    {
        clearKeyboardBuffer();
        /* scan for car length and direction */
        scanf("%d %s", &car_len, direction);

        /* test the string using strcmp */
        if (strcmp(direction, "left") == 0)
        {
            status = queue_enqueue(left, car_len);
        }
        else if (strcmp(direction, "right") == 0)
        {
            status = queue_enqueue(right, car_len);
        }
        else
        {
            status = FAILURE;
        }

        /* test if adding to the queue failed */
        if (status == FAILURE)
        {
            printf("Error adding car to list\n");
            if (left != NULL)
            {
                queue_destory(&left);
            }
            if (right != NULL)
            {
                queue_destory(&right);
            }

            exit(1);
        }
    }

    return ferry_len;
}

int travel(QUEUE left, QUEUE right, int length)
{
    int crossed = 0;
    QUEUE current_bank = left;
    QUEUE other_bank = right;
    while (queue_get_size(current_bank) > 0 || queue_get_size(other_bank) > 0)
    {
        if (queue_get_size(current_bank) != 0)
        {
            load_ferry(current_bank, length);
        }
        crossed++;

        /* swap focused and unfocused queues */
        QUEUE temp = current_bank;
        current_bank = other_bank;
        other_bank = temp;
    }

    return crossed;
}

void load_ferry(QUEUE hQ, int length)
{
    float ferry = 0.0;
    /* we have to traverse from Lbank --> Rbank*/

    while (ferry < length)
    {
        /* list is empty? just quit :) */
        if (queue_get_size(hQ) == 0)
        {
            break;
        }

        /* ferry is full? quit :) */
        if (((*(queue_front(hQ, NULL))*CONVERSION) + ferry) > length)
        {
            break;
        }

        ferry += *(queue_front(hQ, NULL))*CONVERSION;

        queue_service(hQ);
    }
}

void clearKeyboardBuffer(void)
{
    char c = 'a';
    while (c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}

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
    Queue *pQ = (Queue *)hQ;
    Node *temp;

    /* test if hQ is valid */
    if (hQ == NULL)
    {
        printf("error\n");
        exit(1);
    }

    temp = pQ->front;
    while (temp != NULL)
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

int *queue_front(QUEUE hQ, Status *pStatus)
{
    /* cast to the known type */
    Queue *pQ = (Queue *)hQ;
    if (queue_is_empty(hQ) == TRUE)
    {
        if (pStatus == NULL)
        {
            *pStatus = FAILURE;
        }
        return -1337;
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
    Node *temp;
    if (queue_is_empty(hQ) == TRUE)
    {
        return FAILURE;
    }

    /* store the front of the queue and move the front to the next node */
    temp = pQ->front;
    pQ->front = pQ->front->next;

    /* test if the front is NULL */
    if (pQ->front == NULL)
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
    Queue *pQ = (Queue *)hQ;
    if (hQ != NULL)
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
    Node *temp = pQ->front;
    while (temp != NULL)
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

int get_size(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
