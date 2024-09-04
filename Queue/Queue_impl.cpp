#include <iostream>
using namespace std;

class Queue{
  private:
  int *arr;
  int size;
  int front;
  int rear;

  public:
  Queue(int size){
    this->size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void push(int data){
    // Overflow Case
    if(rear == size-1){
      cout << "Queue Overflow" << endl;
      return;
    }
    // Single Element
    else if(front == -1 && rear == -1){
      front++;
      rear++;
      arr[rear] = data;
    }
    // Normal Case
    else{
      rear++;
      arr[rear] = data;
    }
  }

  void pop(){
    // Underflow Case
    if(front == -1 && rear == -1){
      cout << "Empty Queue, Cannot POP!" << endl;
      return;
    }
    // Single Element
    else if(front == rear){
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    // Normal Case
    else{
      arr[front] = -1;
      front++;
    }
  }

  int getSize(){
    if(front == -1 && rear == -1){
      return 0;
    }
    return rear - front + 1;
  }

  int getFront(){
    if(front == -1){
      return 0;
    }
    return arr[front];
  }

  int getRear(){
    if(rear == -1){
      return 0;
    }
    return arr[rear];
  }

  void display(){
    cout << endl << "Displaying Queue : " << endl;
    for(int i=0; i<size; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  
  Queue q(5);
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  q.display();

  
  q.pop();
  q.pop();
  q.pop();
  q.display();

  q.pop();
  q.display();

  q.push(99);
  q.display();

  q.pop();
  q.display();

  q.push(10);
  q.display();

  return 0;
}
