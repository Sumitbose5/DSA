#include <iostream>
using namespace std;

// Base / Parent Class
class Animal{
  public:

  void eat(){
    cout << "Eating.." << endl;
  }

  void sleep(){
    cout << "Sleeping.." << endl;
  }
};

// Derived / Child Class
class Dog : public Animal{
  public:

  void bark(){
    cout << "Barking.." << endl;
  }
};


int main() {
  
  Dog d1;
  d1.eat();
  d1.sleep();
  d1.bark();

  // Here we can access all the member functions of the parent class 
  // Therefore we have successfully inherited the parent class(Animal)

  return 0;
}
