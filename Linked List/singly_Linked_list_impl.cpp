#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

class ListNode{
  Node* head;

  public:
  /* Reason: When a new ListNode object is created, it represents an empty linked list. Setting head to NULL makes it clear that the list doesn't contain any elements yet. */
  ListNode(){
    head = NULL;
  }
};

int main(){

  ListNode l1;  // Stack Allocation
  ListNode* l2 = new ListNode();  // Heap Allocation
  
  
  return 0;
}
