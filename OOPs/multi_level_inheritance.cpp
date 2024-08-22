#include <iostream>
using namespace std;

// Base class: Vehicle
class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle constructor called" << endl;
    }

    void start() {
        cout << "Vehicle started" << endl;
    }
};

// Derived class 1: Car (inherits from Vehicle)
class Car : public Vehicle {
public:
    Car() {
        cout << "Car constructor called" << endl;
    }

    void drive() {
        cout << "Car is driving" << endl;
    }
};

// Derived class 2: SportsCar (inherits from Car)
class SportsCar : public Car {
public:
    SportsCar() {
        cout << "SportsCar constructor called" << endl;
    }

    void turboBoost() {
        cout << "SportsCar is using turbo boost!" << endl;
    }
};

int main() {
    SportsCar mySportsCar;

    // Accessing base class and derived class functions
    mySportsCar.start();        // From Vehicle class
    mySportsCar.drive();        // From Car class
    mySportsCar.turboBoost();   // From SportsCar class

    return 0;
}
