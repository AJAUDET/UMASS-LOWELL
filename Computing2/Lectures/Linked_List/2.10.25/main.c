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
Node *recursive_insert_at_tail(Node *head, int value);
void reference_insert_at_tail(Node **pHead, int value);
void recursive_reference_insert_at_tail(Node **pHead, int value);

int sum_list(Node *head);
int recursive_sum_list(Node *head);

int count_list(Node *head);
int recursive_count_list(Node *head);

int main(int argc, char *argv[])
{
    // 42, 107, 36

    Node *head;
    head = NULL;

    recursive_reference_insert_at_tail(&head, 1);
    recursive_reference_insert_at_tail(&head, 2);
    recursive_reference_insert_at_tail(&head, 3);

    printf("The sum is %d\n", recursive_sum_list(head));
    printf("The number of Nodes is %d\n", recursive_count_list(head));

    recursive_output_list(head);

    return 0;
}

int sum_list(Node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->value;
        head = head->next;
    }
    return sum;
}

int recursive_sum_list(Node *head)
{
    if (head != NULL)
    {
        return head->value + recursive_sum_list(head->next);
    }
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

void reference_insert_at_tail(Node **pHead, int value)
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
    if (*pHead == NULL)
    {
        *pHead = (Node *)malloc(sizeof(Node));
        if (*pHead == NULL)
        {
            printf("Failed to allocate space for Node\n");
            exit(1);
        }
        (*pHead)->value = value;
        (*pHead)->next = NULL;
    }
    else
    {
        recursive_reference_insert_at_tail(&((*pHead)->next), value);
    }
}

int count_list(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int recursive_count_list(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + recursive_count_list(head->next);
    }
}