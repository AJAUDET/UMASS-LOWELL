#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int value;
    Node *next;
};

void delete_list(Node *head);
void head_insert(Node **pHead, int value);
Node *list_sum(Node *head1, Node *head2);
void print_list(Node *head);
Node *reverse_list(Node **pHead);

int main(int argc, char *argv[])
{

    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head_sum = NULL;

    head_insert(&head1, 9);
    head_insert(&head1, 8);
    head_insert(&head1, 1);

    head_insert(&head2, 1);
    head_insert(&head2, 1);

    head_sum = list_sum(head1, head2);
    printf("The sum of ");
    print_list(head1);
    printf(" + ");
    print_list(head2);
    printf("\n");
    printf(" = ");
    print_list(head_sum);
    printf("\n");

    delete_list(head1);
    head1 = NULL;
    delete_list(head2);
    head2 = NULL;
    delete_list(head_sum);
    head_sum = NULL;
    return 0;
}

void delete_list(Node *head)
{
    Node *curr = head;
    Node *next;
    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
}

void head_insert(Node **pHead, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Failed to allocate space for Nwe Node\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = *pHead;
    *pHead = new_node;
}
void print_list(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d", curr->value);
        curr = curr->next;
    }
}

Node *list_sum(Node *head1, Node *head2)
{
    Node *num1 = head1;
    Node *num2 = head2;
    Node *head_sum = NULL;

    Node *temp1 = head1->next->next;
    Node *temp2 = head2->next;

    int carry = 0;

    num1 = reverse_list(&num1);
    num2 = reverse_list(&num2);

    while (num1 || num2)
    {
        int sum = carry;
        if (num1 != NULL)
        {

            sum += num1->value;
            num1 = num1->next;
        }
        if (num2 != NULL)
        {
            sum += num2->value;
            num2 = num2->next;
        }
        carry = sum / 10;
        sum %= 10;
        head_insert(&head_sum, sum);
    }

    if (carry > 0)
    {
        head_insert(&head_sum, carry);
    }

    num1 = reverse_list(&temp1);
    num2 = reverse_list(&temp2);

    return head_sum;
}

Node *reverse_list(Node **pHead)
{

    Node *previous = NULL;
    Node *current;
    Node *next;

    current = *pHead;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
