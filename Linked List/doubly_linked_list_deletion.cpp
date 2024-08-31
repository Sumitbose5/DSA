#include <iostream>
using namespace std;

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

  void insertAtHead(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
      head = newNode;
    }
    else{
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  Node* getTail(){
    Node* temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    return temp;
  }

  void insertAtTail(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
      head = newNode;
    }
    else{
      Node* tail = getTail();
      tail->next = newNode;
      newNode->prev = tail;
    }
  }

  void insertInBtw(int val, int pos){
    Node* newNode = new Node(val);
    
    Node* curr = head;
    Node* prevNode = NULL;
    while(pos != 1){
      prevNode = curr;
      curr = curr->next;
      pos--;
    }
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = curr;
    curr->prev = newNode;
  }

  void insertAtPosition(int val, int pos){
    int len = length();
    if(pos <= 1){
      insertAtHead(val);
    }
    else if(pos >= len+1){
      insertAtTail(val);
    }
    else{
      insertInBtw(val,pos);
    }
  }

  void deleteNode(int pos){
    if(head == NULL){
      cout << "Cannot delete, Linked List is Empty!!" << endl;
      return;
    }
    int len = length();
    if(pos < 1 || pos > len){
      cout << "Position out of bound!" << endl;
      return;
    }

    if(pos == 1){
      Node* temp = head;
      head = head->next;
      if(head != NULL){
        head->prev = NULL;
      }
      delete temp;
    }
    else if(pos == len){
      Node* tail = getTail();
      Node* temp = tail;
      tail = tail->prev;
      tail->next = NULL;
      temp->prev = NULL;
      delete temp;
    }
    else{
      Node* prevNode = NULL;
      Node* curr = head;

      while(pos != 1){
        prevNode = curr;
        curr = curr->next;
        pos--;
      }
      Node* temp = curr;
      curr = curr->next;
      prevNode->next = curr;
      curr->prev = prevNode;
      temp->prev = NULL;
      temp->next = NULL;
      delete temp;
    }
  }

  int length(){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
      len++;
      temp = temp->next;
    }
    return len;
  }

  void display(){
    Node* temp = head;
    if(temp == NULL){
      cout << "Empty Linked List" << endl;
      return;
    }
    while(temp != NULL){
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  
  DoubleListNode d1;
  // Insertion
  d1.insertAtTail(10);
  d1.insertAtTail(20);
  d1.insertAtTail(30);
  d1.insertAtTail(40);
  d1.insertAtTail(50);
  d1.insertInBtw(88,3);
  d1.insertAtPosition(99,2);
  d1.insertAtPosition(99,10);
  d1.insertAtPosition(101,0);

  d1.display();

  // Deletion
  d1.deleteNode(4);
  d1.display();

  d1.deleteNode(2);
  d1.display();

  d1.deleteNode(7);
  d1.display();

  d1.deleteNode(1);
  d1.display();

  d1.deleteNode(4);
  d1.display();

  d1.deleteNode(1);
  d1.display();

  d1.deleteNode(3);
  d1.display();

  d1.deleteNode(1);
  d1.display();

  // // This is the example of the above important condtion
  d1.deleteNode(1);
  d1.display();

  d1.deleteNode(1);
  d1.display();


  return 0;
}
