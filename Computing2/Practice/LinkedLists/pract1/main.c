/*
    Linked List Practice 2.10.25
*/
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

void print_node(Node *head);
void recursive_print_node(Node *head);

Node *reverse_node(Node *head);

Node *insert_at_tail(Node *head, int value);
Node *recursive_insert_at_tail(Node *head, int value);
void reference_insert_at_tail(Node **pHead, int value);
void recursive_reference_insert_at_tail(Node **pHead, int value);

int sum_list(Node *head);
int recursive_sum_list(Node *head);

int count_list(Node *head);
int recursive_count_list(Node *head);

int main(void)
{
    Node *head;
    Node *temp;
    head = NULL;

    // 36, 42, 107, 55, 32 = 272

    head = insert_at_tail(head, 36);
    head = insert_at_tail(head, 42);
    head = insert_at_tail(head, 107);
    head = insert_at_tail(head, 55);
    head = insert_at_tail(head, 32);

    recursive_print_node(head);
    head = reverse_node(head);
    print_node(head);
    printf("There are %d Nodes\n", recursive_count_list(head));
    printf("The sum of the nodes is: %d\n\n", recursive_sum_list(head));
    head = NULL;

    // 77, 12, 190, 4, 2 = 285

    head = recursive_insert_at_tail(head, 77);
    head = recursive_insert_at_tail(head, 12);
    head = recursive_insert_at_tail(head, 190);
    head = recursive_insert_at_tail(head, 4);
    head = recursive_insert_at_tail(head, 2);

    recursive_print_node(head);
    head = reverse_node(head);
    print_node(head);
    printf("There are %d Nodes\n", recursive_count_list(head));
    printf("The sum of the nodes is: %d\n\n", recursive_sum_list(head));
    head = NULL;

    // 22, 1, 32, 535, 90 = 680
    reference_insert_at_tail(&head, 22);
    reference_insert_at_tail(&head, 1);
    reference_insert_at_tail(&head, 32);
    reference_insert_at_tail(&head, 535);
    reference_insert_at_tail(&head, 90);

    recursive_print_node(head);
    head = reverse_node(head);
    print_node(head);
    printf("There are %d Nodes\n", recursive_count_list(head));
    printf("The sum of the nodes is: %d\n\n", recursive_sum_list(head));
    head = NULL;

    // 1, 2 , 3, 4 ,5 = 15
    recursive_reference_insert_at_tail(&head, 1);
    recursive_reference_insert_at_tail(&head, 2);
    recursive_reference_insert_at_tail(&head, 3);
    recursive_reference_insert_at_tail(&head, 4);
    recursive_reference_insert_at_tail(&head, 5);

    recursive_print_node(head);
    head = reverse_node(head);
    print_node(head);
    printf("There are %d Nodes\n", recursive_count_list(head));
    printf("The sum of the nodes is: %d\n\n", recursive_sum_list(head));
    head = NULL;

    return 0;
}

// printing nodes
void print_node(Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void recursive_print_node(Node *head)
{
    if (head != NULL)
    {
        printf("%d->", head->data);
        recursive_print_node(head->next);
    }
    else
    {
        printf("NULL\n");
    }
}

// reversing nodes
Node *reverse_node(Node *head)
{
    Node *current = NULL;
    Node *temp;
    Node *next;
    temp = head;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = current;
        current = temp;
        temp = next;
    }
    return current;
}

// inserting numbers into the nodes
Node *insert_at_tail(Node *head, int value)
{
    Node *temp;
    Node *current;

    temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Error allocating space for a new node\n");
        exit(1);
    }
    temp->data = value;
    temp->next = NULL;

    // test the cases, 0, 1 , many
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
    return head;
}
Node *recursive_insert_at_tail(Node *head, int value)
{
    Node *temp;
    if (head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        if (head == NULL)
        {
            printf("Failed to allocate space for Node\n");
            exit(1);
        }
        head->data = value;
        head->next = NULL;
    }
    else
    {
        head->next = recursive_insert_at_tail(head->next, value);
    }
    return head;
}
void reference_insert_at_tail(Node **pHead, int value)
{
    Node *temp;
    Node *current;

    temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Error allocating space for a new node\n");
        exit(1);
    }
    temp->data = value;
    temp->next = NULL;

    // test the cases, 0, 1 , many
    if (*pHead == NULL)
    {
        *pHead = temp;
    }
    else
    {
        current = *pHead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}
void recursive_reference_insert_at_tail(Node **pHead, int value)
{
    Node *temp;
    if (*pHead == NULL)
    {
        *pHead = (Node *)malloc(sizeof(Node));
        if (*pHead == NULL)
        {
            printf("Failed to allocate space for Node\n");
            exit(1);
        }
        (*pHead)->data = value;
        (*pHead)->next = NULL;
    }
    else
    {
        recursive_reference_insert_at_tail(&(*pHead)->next, value);
    }
}

// sum of the nodes
int sum_list(Node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->data;
    }
    return sum;
}
int recursive_sum_list(Node *head)
{
    while (head != NULL)
    {
        return head->data + recursive_sum_list(head->next);
    }
    return 0;
}

// number of nodes
int count_list(Node *head)
{
    int nodes = 0;
    while (head != NULL)
    {
        nodes++;
        head = head->next;
    }
    return nodes;
}

int recursive_count_list(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + recursive_count_list(head->next);
    }
}