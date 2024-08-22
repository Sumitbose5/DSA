/* In C++, the friend keyword is used to grant a non-member function or another class access to the private and protected members of a class. It breaks the usual encapsulation rules by allowing external functions or classes to access the internals of a class.

Friend Function: A non-member function that has access to the private and protected members of a class */

#include <iostream>
using namespace std;

class Box {
private:
    double width;

public:
    // Constructor to initialize the width
    Box(double w) : width(w) {}

    // Declaring a friend function
    friend void printWidth(Box box);
};

// Friend function definition
void printWidth(Box box) {
    // Accessing private member width
    cout << "Width of the box: " << box.width << endl;
}

int main() {
    Box box(10.5);
    
    // Calling friend function
    printWidth(box);

    return 0;
}
