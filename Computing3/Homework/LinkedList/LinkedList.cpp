#include "LinkedList.hpp"

Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::Node(int new_data, Node* new_next)
{
    data = new_data;
    next = new_next;
}

Node::Node(int new_data)
{
    data = new_data;
    next = nullptr;
}

// post condition: returns the value of the current node
const int Node::getData() const
{
    return data;
}

// pre condition: valid data type
// post condition: Node data variable set to the new value
void Node::setData(int new_data)
{
    data = new_data;
}

// post condition: returns a pointer to the next Node stored in memory
Node* Node::getNext() const
{
    return next;
}

// pre condition: valid Node* is given to the function
// post condition: the next Node in memory is set to the given Node
void Node::setNext(Node* new_next)
{
    next = new_next;
}

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::LinkedList(int data)
{
    head = new Node(data);
}

LinkedList::LinkedList(Node* node)
{
    head = node;
}

// create a deep copy of the given list
LinkedList::LinkedList(const LinkedList& list)
{
    // check if the list is empty
    if (list.head == nullptr)
    {
        head = nullptr;
    }

    // set the head to a new node
    // track where we are to copy ove the rest of the nodes
    head = new Node(list.head->getData());
    Node* curr = head;
    Node* temp = list.head->getNext();

    // while we are not at the end of the list
    while (temp != nullptr)
    {
        curr->setNext(new Node(temp->getData()));
        curr = curr->getNext();
        temp = temp->getNext();
    }
}

LinkedList::LinkedList(int* arr, int size)
{
    head = nullptr;
    for (int i = 0; i < size; i++)
        preAppend(arr[i]);
}

// post condition: return the item(s) stored in the linekd list
const Node* LinkedList::getHead() const
{
    return head;
}

// pre condition: valid Node is given
// post condition: the head is the given Node, and the following Nodes are the ones attached to the given Node
void LinkedList::setHead(Node* new_head)
{
    head = new_head;
}

// pre consdition: valid data type is given
// post condition: data given is the new head Node
void LinkedList::preAppend(int data)
{
    Node* new_head = new Node(data, head);
    head = new_head;
}

// pre consdition: valid data type is given
// post condition: data given is the new last Node
void LinkedList::postAppend(int data)
{
    Node* temp = new Node(data);

    if (head == nullptr)
    {
        head = temp;
    }

    Node* curr = head;
    while (curr->getNext() != nullptr)
        curr = curr->getNext();
    curr->setNext(temp);
}

ostream& operator<<(ostream& out, const LinkedList& list)
{
    Node* curr = list.head;
    while (curr != nullptr)
    {
        out << curr->getData();
        if (curr->getNext() != nullptr)
            out << "->";
        curr = curr->getNext();
    }
    out << "->nullptr";
    return out;
}
