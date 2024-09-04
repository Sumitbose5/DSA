#include<iostream>
using namespace std;

class Deque{
  private:
  int *arr;
  int size;
  int front;
  int rear;

  public:
  Deque(int size){
    this->size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void pushBack(int data){
    // Overflow
    if((front == 0 && rear == size - 1) || front - rear == 1){
      cout << "Queue Overflow!" << endl;
      return;
    }
    // Empty
    else if(front == -1 && rear == -1){
      front++;
      rear++;
      arr[front] = data;
    }
    // Circular
    else if(rear == size - 1 && front != 0){
      rear = 0;
      arr[rear] = data;
    }
    // Normal
    else{
      rear++;
      arr[rear] = data;
    }
  }

  void pushFront(int data){
    // Overflow
    if((front == 0 && rear == size - 1) || (front - rear == 1)){
      cout << "Queue Overflow!" << endl;
    }
    // Empty
    else if(front == -1 && rear == -1){
      front++;
      rear++;
      arr[front] = data;
    }
    // Circular
    else if(front == 0 && rear != size - 1){
      front = size - 1;
      arr[front] = data;
    }
    // Normal
    else{
      front--;
      arr[front] = data;
    }
  }

  void popBack(){
    // Underflow
    if(front == -1 && rear == -1){
      cout << "Empty Queue, Cannot PoP!" << endl;
    }
    // Single Element
    else if(front == rear){
      arr[rear] = -1;
      front = -1;
      rear = -1;
    }
    // Circular
    else if(rear == 0){
      arr[rear] = -1;
      rear = size - 1;
    }
    // Normal
    else{
      arr[rear] = -1;
      rear--;
    }
  }

  void popFront(){
    // Underflow
    if(front == -1 && rear == -1){
      cout << "Empty Queue, Cannot pop!" << endl;
    }
    // Single Element
    else if(front == rear){
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    // Circular
    else if(front == size - 1){
      arr[front] = -1;
      front = 0;
    }
    // Normal
    else{
      arr[front] = -1;
      front++;
    }
  }

  int getFront(){
    if(front == -1){
      return 0;
    }
    else{
      return arr[front];
    }
  }

  int getRear(){
    if(rear == -1){
      return 0;
    }
    else{
      return arr[rear];
    }
  }

  int getSize() {
      if(front == -1 && rear == -1){
          return 0; // Queue is empty
      } 
      else if(rear >= front){
          return rear - front + 1; // Normal case
      } 
      else{
          return (size - front) + (rear + 1); // Circular case
      }
  }


  void display(){
    cout << endl <<  "Displaying Queue : " << endl;
    for(int i=0; i<size; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }

};

int main(){
  
  Deque d(5);
  d.pushBack(10);
  d.pushBack(20);
  d.pushBack(30);

  d.display();

  d.pushFront(5);
  d.display();

  d.popFront();
  d.display();
  d.pushFront(9);
  d.pushFront(33);
  d.display();

  cout << "Front Element : " << d.getFront() << endl;
  d.popBack();
  d.display();
  d.popFront();
  d.display();
  cout << "Size : " << d.getSize() << endl;
  
  return 0;
}
