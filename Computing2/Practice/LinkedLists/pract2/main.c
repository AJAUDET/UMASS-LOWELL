#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

void insert_at_head(Node **pHead, int data);
void insert_at_tail(Node **pHead, int data);
void print_list(Node *head);
void reverse_list(Node **pHead);
void destroy_list(Node *head);

int main(void)
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    // value 123 for head1
    insert_at_head(&head1, 3);
    insert_at_head(&head1, 2);
    insert_at_head(&head1, 1);

    // value 456 for head 2
    insert_at_tail(&head2, 4);
    insert_at_tail(&head2, 5);
    insert_at_tail(&head2, 6);

    print_list(head1);
    print_list(head2);

    reverse_list(&head1);
    reverse_list(&head2);

    print_list(head1);
    print_list(head2);

    destroy_list(head1);
    head1 = NULL;
    destroy_list(head2);
    head2 = NULL;

    return 0;
}

void insert_at_head(Node **pHead, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Error allocating memory for new node\n");
        exit(1);
    }
    temp->data = data;
    temp->next = *pHead;
    *pHead = temp;
}

void insert_at_tail(Node **pHead, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    Node *current;
    if (temp == NULL)
    {
        printf("Error allocating memory for new node\n");
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
        current = *pHead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void print_list(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void reverse_list(Node **pHead)
{
    Node *curr = *pHead;
    Node *prev = NULL;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *pHead = prev;
}

void destroy_list(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
}
