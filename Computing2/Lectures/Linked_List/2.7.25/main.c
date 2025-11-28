#include <stdio.h>
#include <stdlib.h>

struct node; // forward declaration
typedef struct node Node;

struct node
{
    int value;
    Node *next;
};

void output_list(Node *head);
void recursive_output_list(Node *head);

Node *insert_at_tail(Node *head, int value);
void reference_insert_at_tail(Node **pHead, int value);
Node *recursive_insert_at_tail(Node *head, int value);
void recursive_reference_insert_at_tail(Node **pHead, int value);

int main(int argc, char *argv[])
{
    // 42, 107, 36

    Node *head;
    head = NULL;

    head = recursive_insert_at_tail(head, 42);
    head = recursive_insert_at_tail(head, 107);
    head = recursive_insert_at_tail(head, 36);

    recursive_output_list(head);

    return 0;
}

void output_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void recursive_output_list(Node *head)
{
    if (head != NULL)
    {
        printf("%d->", head->value);
        recursive_output_list(head->next);
    }
    else
    {
        printf("NULL\n");
    }
}

Node *insert_at_tail(Node *head, int value)
{
    Node *temp;
    Node *current;
    temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Failed to allocate space for Node\n");
        exit(1);
    }
    temp->value = value;
    temp->next = NULL;

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
        head->value = value;
        head->next = NULL;
    }
    else
    {
        head->next = recursive_insert_at_tail(head->next, value);
    }
    return head;
}

void recursive_reference_insert_at_tail(Node **pHead, int value)
{
}

void reference_insert_at_tail(Node **pHead, int value)
{
}