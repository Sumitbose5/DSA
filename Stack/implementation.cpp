#include <iostream>
using namespace std;

class Stack{
public:
  int *arr;
  int top;
  int size;

  Stack(int size){
    arr = new int[size];
    this->top = -1;
    this->size = size;
  }

  // Method to push an element onto the stack
  void push(int data){
    // Overflow Condition
    if(top == size - 1){
      cout << "Stack Overflow" << endl;
      return;
    }
    else{
      top++;
      arr[top] = data;
    }
  }

  // Method to pop an element from the stack
  void pop(){
    // Underflow Condition
    if(top == -1){
      cout << "Stack Underflow" << endl;
      return;
    }
    else{
      arr[top] = -1;
      top--;
    }
  }

  // Method to get the top element of the stack
  int getTop(){
    // Stack Empty
    if(top == -1){
      cout << "Stack is Empty" << endl;
      return -1;
    }
    return arr[top];
  }

  // Method to get the current size of the stack
  int getSize(){
    return top + 1;
  }

  // Method to check if the stack is empty
  bool checkEmpty(){
    if(top == -1){
      return true;
    }
    return false;
  }
};

int main() {
  Stack st(5);
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  st.push(60); // output -> Stack Overflow

  cout << "Size of Stack : " << st.getSize() << endl;
  // output -> 5

  st.pop();
  st.pop();

  cout << "Top Element of the Stack : " << st.getTop() << endl;
  // output -> 30

  bool ans = st.checkEmpty();
  if(ans)
    cout << "Stack is Empty" << endl;
  else  
    cout << "Not Empty" << endl;

  // output -> Not Empty

  return 0;
}
