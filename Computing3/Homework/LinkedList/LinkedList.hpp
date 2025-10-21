#include <iostream>
using namespace std;

class Node {
 private:
  int data;
  Node* next;
 public:
  Node();                                   // Defauly Constructor
  Node(int new_data);                       // Value Constructor
  Node(int new_data, Node* new_next);       // Node Constructor

  const int getData() const;
  Node* getNext() const;
  void setData(int new_data);
  void setNext(Node* new_next);
};

class LinkedList
{
 private:
  Node* head;
 public:
  LinkedList();                             // Deafult Constructor
  LinkedList(int data);                     // Value Constructor
  LinkedList(Node* node);                   // Node Constructor
  LinkedList(const LinkedList& list);       // Copy Constructor
  LinkedList(int* arr, int size);           // Array Constructor

  void preAppend(int data);
  void postAppend(int data);
  void setHead(Node* new_head);
  const Node* getHead() const;

  friend ostream& operator<<(ostream& out, const LinkedList& list);
};

ostream& operator<<(ostream& out, const LinkedList& list);
