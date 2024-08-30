#include <iostream>
using namespace std;

// Creating a Class For Doubly Linked List
class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  Node(int val){
    data = val;
    this->next = NULL;
    this->prev = NULL;
  }
};

class DoubleListNode{
  Node* head;

  public:
  DoubleListNode(){
    head = NULL;
  }

// Write all the functions here
};
