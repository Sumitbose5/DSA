#include <iostream>
#include<stack>
using namespace std;

// Find the middle Element in a Stack

int solve(stack<int>& st, int pos){
  // Base Case
  if(pos == 1)
    return st.top();

  pos--;
  int temp = st.top();
  st.pop();

  // Recursive Call
  return solve(st, pos);

  // Backtracking
  st.push(temp);
}

int middleElement(stack<int>& st){
  int size = st.size();
  int pos = 0;

  if(st.empty()){
    cout << "Stack is Empty" << endl;
    return 0;
  }
  else{
    if(size & 1){  // ODD
      pos = size / 2 + 1;
    }
    else{  // EVEN
      pos = size / 2;
    }
  }

  return solve(st, pos);
}

int main() {

  stack<int>st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  // st.push(60);

  int ans = middleElement(st);
  cout << "Middle Element : " << ans << endl; // output -> 30
  
  // In case of Even Number the middle element will be 40 (suppose that we pushed 60)
  
  return 0;
}
