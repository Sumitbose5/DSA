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


  Node* createTail(){
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
      Node* tail = createTail();
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
    while(temp != NULL){
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << endl;
  }

};

int main() {
  
  DoubleListNode d1;
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

  return 0;
}
