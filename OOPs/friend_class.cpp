/* Friend Class: Another class that has access to the private and protected members of the class in which it is declared as a friend. */

#include <iostream>
using namespace std;

class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    // Declaring Car as a friend class
    friend class Car;
};

class Car {
public:
    void showHorsepower(Engine engine) {
        // Accessing private member horsepower of Engine
        cout << "Car's engine horsepower: " << engine.horsepower << endl;
    }
};

int main() {
    Engine engine(400);
    Car car;
    
    car.showHorsepower(engine);

    return 0;
}

// Output -> Car's engine horsepower: 400
