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

void head_insert(Node **pHead, int data);

void tail_insert(Node **pHead, int data);
Node *recursive_tail_insert(Node *head, int data);
void ref_rec_tail_insert(Node** pHead, int data);

void print_nodes(Node *head);
void destroy_nodes(Node *head);

int sum_nodes(Node* head);

int main(void)
{
    Node *head1 = NULL;
    int i;

    for (i = 0; i < 11; i++)
    {
        tail_insert(&head1, i);
    }
    
    ref_rec_tail_insert(&head1, 100);

    printf("Head1: ");
    print_nodes(head1);
    printf("\n");

    destroy_nodes(head1);
    return 0;
}

void print_nodes(Node *head)
{
    if (head != NULL)
    {
        printf("%d->", head->data);
        print_nodes(head->next);
    }
    else
    {
        printf("NULL");
    }
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

int sum_nodes(Node* head)
{
    return (head != NULL) ? head->data + sum_nodes(head->next): 0;
}

void ref_rec_tail_insert(Node** pHead, int data)
{
    if(*pHead == NULL)
    {
        *pHead = (Node*)malloc(sizeof(Node));
        if(*pHead == NULL) exit(1);
        (*pHead)->data = data;
        (*pHead)->next = NULL;
    }
    else{
        ref_rec_tail_insert(&((*pHead)->next), data);
    }
}

void destroy_nodes(Node *head)
{
    if (head == NULL)
    {
        exit(0);
    }
    destroy_nodes(head->next);
    free(head);
}

