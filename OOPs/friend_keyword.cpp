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
