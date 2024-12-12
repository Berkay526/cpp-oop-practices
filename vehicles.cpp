#include <iostream>
#include <string>

class Vehicle {
private:
    std::string name;
    std::string color;
    int age;

public:
    Vehicle(std::string name, std::string color, int age) : name(name), color(color), age(age) {}

    void display() const {
        std::cout << "Name : " << name 
                  << "\nColor : " << color 
                  << "\nAge : " << age 
                  << std::endl;
    }
};

class Car : public Vehicle { 
private:
    std::string brand;
    int engineHP;

public:
    Car(std::string name, std::string color, int age, std::string brand, int engineHP)
        : Vehicle(name, color, age), brand(brand), engineHP(engineHP) {}

    void displayCar() const {
        display(); 
        std::cout << "Brand : " << brand 
                  << "\nEngine HP : " << engineHP 
                  << std::endl;
    }
};

int main() {
    Car car1("Ferrari SF90 Spider", "Red", 4, "Ferrari S.p.A.", 1000);
    car1.displayCar(); 
    return 0;
}