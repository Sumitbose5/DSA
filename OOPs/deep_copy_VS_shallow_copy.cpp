#include <iostream>
using namespace std;

class Demo{
  public:
  int size;
  int *arr;

  // Constructor
  Demo(int s) : size(s){
    arr = new int[size];
    for(int i=0; i<size; i++){
      arr[i] = i+1;
    }
  } 

  // Copy Constructor for Shallow Copy
  Demo(Demo &obj) : size(obj.size), arr(obj.arr){}

  // Copy Constructor for Deep Copy
  Demo(Demo &obj, bool deep) : size(obj.size){
    if(deep){
      arr = new int[size];
      for(int i=0; i<size; i++){
        arr[i] = obj.arr[i];
      }
    }
    else{
      arr = obj.arr;
    }
  }

  // Destructor
  ~Demo(){
    delete[] arr;
  }

  // Print array
  void printData(){
    for(int i=0; i<size; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  // Modify data at a specific index
  void modifyData(int index, int value) {
    if (index >= 0 && index < size) {
      arr[index] = value;
    }
  }
};

int main() {

  Demo obj1(5);
  cout << "Original object data : ";
  obj1.printData();

  // Shallow Copy
  Demo obj2 = obj1;     // Uses the shallow copy constructor
  cout << "Shallow copied object data : ";
  obj2.printData();

  // Deep copy
  Demo obj3(obj1, true);  // Uses the deep copy constructor

  // Modify original object data to see the effect on shallow copy
  obj1.printData();
  cout << "After modifying original object, shallow copied object data: ";
  obj1.modifyData(2,88);
  obj2.printData();

  cout << "Original object data : ";
  obj1.printData();

  cout << "Deep copied object data: ";
  obj3.printData();

  return 0;
}
