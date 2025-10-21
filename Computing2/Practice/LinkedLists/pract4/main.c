#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

int recursive_count_nodes(Node *head);
int count_nodes(Node *head);
void insert_at_head(Node **pHead, int data);
void insert_at_tail(Node **pHead, int data);
int recursive_sum(Node *head);
void destroy_nodes(Node *head);
Node *copy_list(Node *head);
void print_list(Node *head);

int main(void)
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    insert_at_tail(&head1, 1);
    insert_at_tail(&head1, 2);
    insert_at_tail(&head1, 3);

    printf("Head1 : ");
    print_list(head1);

    head2 = copy_list(head1);

    printf("Head2 : ");
    insert_at_head(&head2, 0);
    print_list(head2);

    return 0;
}

void print_list(Node *head)
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
        temp = (Node*)malloc(sizeof(Node));
        if(temp == NULL)
        {
            fprintf(stderr, "oops");
            exit(1);
        }
        temp->data = head->data;
        temp->next = copy_list(head->next);
    }
    return temp;
}

void insert_at_tail(Node **pHead, int data)
{
    Node *current;
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
        current = *pHead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

int recursive_sum(Node *head)
{
    if (head != NULL)
    {
        return head->data + recursive_sum(head->next);
    }
    return 0;
}

void insert_at_head(Node **pHead, int data)
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

int recursive_count_nodes(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count_nodes(head->next);
    }
}

void destroy_nodes(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void destroy_recursive(Node *head)
{
    if (head == NULL)
    {
        exit(0);
    }
    destroy_recursive(head->next);
    free(head);
}
