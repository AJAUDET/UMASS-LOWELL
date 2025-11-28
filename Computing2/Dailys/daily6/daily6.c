/*
    Author: AJ Audet
    Date: 2.12.25
    Effort:  30 Mins
    Purpose: Practicing Linked Lists and being able to write them, and reverse them, this design is to be used in day6B
    Program: daily6.c

    driver code copied over from starter.c
*/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

// declare your function here.
Node *reverse_my_nodes(Node *head);

int main(int argc, char *argv[])
{
    Node *head = NULL;
    int i;
    Node *temp;

    // set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("out of memory?\n");
            exit(1);
        }
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // call your function to reverse the list (should work for any list given the head node pointer).
    head = reverse_my_nodes(head);

    // print the reversed list.
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

// Define your function here

Node *reverse_my_nodes(Node *head)
{
    // three pointers
    Node *previous = NULL;
    Node *current;
    Node *next;

    current = head;
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