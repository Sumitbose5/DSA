#include <iostream>
using namespace std;

class CQueue{
  private:
  int *arr;
  int size;
  int front;
  int rear;

  public:
  CQueue(int size){
    this->size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void push(int data){
    // Overflow Case
    if((front == 0 && rear == size - 1) || front - rear == 1){
      cout << "Queue OverFlow!" << endl;
      return;
    }
    // Single Element
    else if(front == -1 && rear == -1){
      front++;
      rear++;
      arr[rear] = data;
    }
    // CQueue Case
    else if(rear == size - 1 && front != 0){
      rear = 0;
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
      cout << "Cannot pop, Empty Queue!" << endl;
    }
    // Single Element
    else if(front == rear){
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    // CQueue Case
    else if(front == size - 1){
      arr[front] = -1;
      front = 0;
    }
    // Normal Case
    else{
      arr[front] = -1;
      front++;
    }
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

  // TEST CIRCULAR QUEUE --->
  CQueue cq(5);
  cq.push(10);
  cq.push(20);
  cq.push(30);
  cq.push(35);

  cq.display();

  cq.push(55);
  cq.display();

  cq.pop();
  cq.display();
  cq.push(99);
  cq.pop();
  cq.pop();
  cq.pop();
  cq.pop();

  cq.display();

  cq.push(67);
  cq.push(88);

  cq.display();

  cq.pop();
  cq.display();

  cq.push(10);
  cq.push(20);
  cq.push(30);

  cq.display();


  return 0;
}
