#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

void tail_insert(Node **pHead, int data);
Node *recursive_tail_insert(Node *head, int data);

void head_insert(Node **pHead, int data);

void print_list(Node *head);
void destroy_list(Node *head);

int main(void)
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int i;

    tail_insert(&head1, 1);
    tail_insert(&head1, 2);
    tail_insert(&head1, 3);

    head1 = recursive_tail_insert(head1, 4);
    head1 = recursive_tail_insert(head1, 5);
    head1 = recursive_tail_insert(head1, 6);

    head_insert(&head1, 0);

    printf("Head1: ");
    print_list(head1);
    printf("\n");

    for (i = 0; i < 15; i++)
    {
        tail_insert(&head2, i);
    }
    head2 = recursive_tail_insert(head2, 99);
    head_insert(&head2, -1);

    printf("Head2: ");
    print_list(head2);
    printf("\n");

    destroy_list(head1);
    destroy_list(head2);
    return 0;
}

void print_list(Node *head)
{
    if (head != NULL)
    {
        printf("%d->", head->data);
        print_list(head->next);
    }
    else
        printf("NULL");
}

void tail_insert(Node **pHead, int data)
{
    Node *curr;
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        exit(1);
    }

    temp->data = data;
    temp->next = NULL;

    if (*pHead == NULL)
    {
        *pHead = temp;
    }
    else
    {
        curr = *pHead;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

Node *recursive_tail_insert(Node *head, int data)
{
    if (head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        if (head == NULL)
        {
            exit(1);
        }
        head->data = data;
        head->next = NULL;
    }
    else
    {
        head->next = recursive_tail_insert(head->next, data);
    }
    return head;
}

void head_insert(Node **pHead, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        exit(1);
    }
    temp->data = data;
    temp->next = *pHead;
    *pHead = temp;
}

void destroy_list(Node *head)
{
    if (head == NULL)
    {
        exit(0);
    }
    destroy_list(head->next);
    free(head);
}
