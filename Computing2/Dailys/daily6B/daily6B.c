/*
    Program: daily6B.c
    Author: AJ Audet
    Date: 2.14.25
    Time spent: 2 hrs 15 mins
    Purpose: to add two numbers, represented by linked lists, together
        the secret was i dont know im barely even sure that this code is correct tbh
*/

#include <stdio.h>
#include <stdlib.h>

struct node; // forward declaration
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
    // add up 189 + 11
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head_sum = NULL;

    // create a list for the number 189
    head_insert(&head1, 9);
    head_insert(&head1, 8);
    head_insert(&head1, 1);

    // create a list for the number 11
    head_insert(&head2, 1);
    head_insert(&head2, 1);

    /*
        Error 1: seg fault WHY????? :: reason: I tried accessing a value that did not exist
        solution:: protected the values inside of the sum function

        Error 2: only the first value of the linked list is being displayed, the next is NULL?????
        the values are stored correctly but something happens and the values become NULL but are still stored

            Observation 1: something happens with the values and they become 1 and NULL debugging the program has not helped with what the issue
            coule be, i have rewritten my insert at head function and my print function and i dont know why it is not working
            the debugger shows that it happens after the head_sum function

            Observation 2: the error fixes itself when head_sum = ... is moved down, why i dont know it does that
            the error really is not making sense to me

            Observation 3 : the values should not change because we pass over a copy of the values right???

            Observation 4 : something happens in time right after head_sum = ....

            Observation 5 : the values change to NULL after the head_sum line

            Observation 6 : the reverse function mutates head1
            reason :: IT ALL POINTERS AAAAAAAAAAAAAAAA

        // not actual solution :: using head insert to reverse the list fixed the issues
        // solution :: used a temp variable to store h1 / h2
    */
    head_sum = list_sum(head1, head2); // this line is the issue
    printf("The sum of ");
    print_list(head1);
    printf(" + ");
    print_list(head2);
    printf("\n");
    printf(" = ");
    print_list(head_sum);
    printf("\n");

    // clean up three lists
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
    while (curr != NULL)
    {
        Node *next = curr->next;
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
    // 2 Node* to track the original Node
    // 1 Node* to output the "summed" number
    Node *num1 = head1;
    Node *num2 = head2;
    Node *head_sum = NULL;

    // im not sure if doing it this way is right but im lost rn
    Node *temp1 = head1->next->next;
    Node *temp2 = head2->next;

    int carry = 0;

    num1 = reverse_list(&num1);
    num2 = reverse_list(&num2);

    while (num1 || num2)
    {
        // sum becomes the value of carry
        int sum = carry;

        // protect num1 & num2 so we dont access data we dont have
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

        // carry over becomes sum / 10 to remove what ever place we are in to move on
        carry = sum / 10;

        // sum is modded to "remove" the extra place value ie: 18 -> 8 then insert it
        sum %= 10;

        // insert value at head of node
        head_insert(&head_sum, sum);
    }

    // accounting for if carry still has a value
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
    // three pointers
    Node *previous = NULL;
    Node *current;
    Node *next;

    current = *pHead;
    while (current != NULL)
    {
        // next needs to be the next one over
        next = current->next;
        // current->next becomes previous
        current->next = previous;
        // previous becomes the current node
        previous = current;
        // current moves up to the next current
        current = next;
    }
    return previous;
}


/*

    this also works for reversing bc ur inserting at the head

// create a copy of the list and use head insert to input values
    Node *copy = NULL;
    Node *current = *pHead;

    // possible loop condition : while current exists (current) or as long as current is not NULL (current != NULL) either works
    while (current)
    {
        head_insert(&copy, current->value);
        current = current->next;
    }

    // return the copied list
    return copy;

*/
