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

  void insertAtTail(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
      head = newNode;
    }
    else{
      Node* temp = head;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void insertAtHead(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
      head = newNode;
    }
    else{
      newNode->next = head;
      head = newNode;
    }
  }

  void insertInBetween(int val, int pos){
    Node* newNode = new Node(val);
    Node* curr = head;
    Node* prev = NULL;

      while(pos != 1){
        prev = curr;
        curr = curr->next;
        pos--;
      }
      prev->next = newNode;
      newNode->next = curr;
  }

  void insertAtPosition(int val, int pos){
    Node* newNode = new Node(val);
    int len = length();
    if(pos <= 1){
      insertAtHead(val);
    }
    else if(pos >= len+1){
      insertAtTail(val);
    }
    else{
      insertInBetween(val,pos);
    }
  }

  void deleteNode(int pos){
    // Delete Head Node
    int len = length();
    if(head == NULL){
      cout << "Empty Linked List" << endl;
    }
    else if(pos <= 1){
      Node* temp = head;
      head = head->next;
      delete temp;
    }
    else if(pos >= len+1){
      Node* temp = head;
      while(temp->next->next != NULL){
        temp = temp->next;
      }
      temp->next = NULL;
    }
    else{
      Node* curr = head;
      Node* prev = NULL;

      while(pos != 1){
        prev = curr;
        curr = curr->next;
        pos--;
      }
      prev->next = curr->next;
      curr->next = NULL;
      delete curr;
    }
  }

  int length(){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
      len++;
      temp = temp->next;
    }
    return len;
  }

  void display(){
    Node* temp = head;
    while(temp != NULL){
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  
  ListNode l1;
  // l1.insertAtHead(10);
  // l1.insertAtHead(20);
  // l1.insertAtHead(30);
  // l1.insertAtHead(40);
  // l1.insertAtHead(50);
  l1.insertAtPosition(10,1);
  l1.insertAtPosition(20,2);
  l1.insertAtPosition(30,3);
  l1.insertAtPosition(40,4);
  l1.insertAtPosition(100,4);
  l1.insertAtPosition(99,5);
  l1.insertAtPosition(234,7);

  l1.deleteNode(1);
  l1.display();

  l1.deleteNode(6);
  l1.display();

  l1.deleteNode(3);
  l1.display();

  l1.deleteNode(2);
  l1.display();

  int len = l1.length();
  cout << "Length : " << len << endl;


  return 0;
}
