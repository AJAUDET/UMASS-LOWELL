#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

void insert_at_tail(Node **pHead, int value);
void insert_at_head(Node **pHead, int value);
int count_node(Node *head);
void print_nodes(Node *head);

int main(void)
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    insert_at_head(&head1, 2);
    insert_at_head(&head1, 1);
    insert_at_head(&head1, 3);

    print_nodes(head1);

    printf("There are %d nodes\n", count_node(head1));

    insert_at_head(&head1, -5);
    insert_at_head(&head1, -8);
    insert_at_head(&head1, 4);

    print_nodes(head1);

    printf("There are %d positive nodes\n", count_node(head1));
}

void insert_at_head(Node **pHead, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Error allocating space for a new Node\n");
        exit(1);
    }
    node->data = value;
    node->next = *pHead;
    *pHead = node;
}

void insert_at_tail(Node **pHead, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    Node *current;
    if (node == NULL)
    {
        printf("Error allocating space for a new Node\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;

    if (*pHead == NULL)
    {
        *pHead = node;
    }
    else
    {
        current = *pHead;
        while (current != NULL)
        {
            current = current->next;
        }
        current->next = node;
    }
}

void print_nodes(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int count_node(Node *head)
{
    int node_count = 0;
    while (head != NULL)
    {
        if(head->data >= 0)
            node_count++;
        head = head->next;
    }
    return node_count;
}