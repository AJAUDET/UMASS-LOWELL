#include <stdlib.h>
#include <stdio.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

void tail_insert(Node **pHead, int data);
void head_insert(Node **pHead, int data);
void destroy_list(Node *head);
int count_nodes(Node *head);
int count_nodes_recursive(Node *head);
Node *copy_list(Node *head);
void print_list(Node* head);

int main(int argc, char *argv[])
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    tail_insert(&head1, 1);
    tail_insert(&head1, 2);
    tail_insert(&head1, 3);

    printf("Head1 : ");
    print_list(head1);
    printf("There are %d nodes\n", count_nodes(head1));

    head2 = copy_list(head1);

    printf("Head2 : ");
    head_insert(&head2, 0);
    print_list(head2);
    printf("There are %d nodes\n", count_nodes_recursive(head2));

    return 0;
}

void print_list(Node* head)
{
    if(head != NULL)
    {
        printf("%d->", head->data);
        print_list(head->next);
    }
    else
        printf("NULL\n");
}

Node *copy_list(Node *head)
{
    Node *temp;
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            exit(1);
        }
        temp->data = head->data;
        temp->next = copy_list(head->next);
    }
    return temp;
}

int count_nodes(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int count_nodes_recursive(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count_nodes_recursive(head->next);
    }
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

void destroy_list(Node *head)
{
    if (head == NULL)
    {
        exit(0);
    }
    destroy_list(head->next);
    free(head);
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
