#include <iostream>
#include <string>

// generate a new class
class Vehicle {
private:
    //declare variables
    std::string m_name;
    std::string m_color;
    int m_age;

public:
    // declare the constructor function
    Vehicle(std::string m_name, std::string m_color, int m_age)
     : m_name(m_name), 
       m_color(m_color), 
       m_age(m_age) {}

    // make const function (func doesn't modify the variables) so that it can access to both const and non-const variables
    void display() const {
        std::cout << "Name : " << m_name 
                  << "\nColor : " << m_color 
                  << "\nAge : " << m_age 
                  << std::endl;
    }
};

class Car : public Vehicle { 
private:
    // declare additional variables
    std::string m_brand;
    int m_engineHP;

public:
    // declare the constructor function of Car class
    Car(std::string m_name, std::string m_color, int m_age, std::string m_brand, int m_engineHP)
        : Vehicle(m_name, m_color, m_age), m_brand(m_brand), m_engineHP(m_engineHP) {}

    void displayCar() const {
        display(); 
        std::cout << "Brand : " << m_brand 
                  << "\nEngine HP : " << m_engineHP 
                  << "\n"
                  << std::endl;
    }
};

class Airplane : public Vehicle { 
private:
    // declare additional variables
    std::string m_brand;
    int m_engineHP;
    double m_wingLengthMeters;

public:
    // declare the constructor function of Airplane class
    Airplane(std::string m_name, std::string m_color, int m_age, std::string m_brand, int m_engineHP, double m_wingLengthMeters)
        : Vehicle(m_name, m_color, m_age), m_brand(m_brand), m_engineHP(m_engineHP), m_wingLengthMeters(m_wingLengthMeters) {}

    void displayPlane() const {
        display(); 
        std::cout << "Brand : " << m_brand 
                  << "\nEngine HP : " << m_engineHP 
                  << "\nWing Length (meters) : " << m_wingLengthMeters
                  << "\n"
                  << std::endl;
    }
};

int main() {
    Car car1("Ferrari SF90 Spider", "Red", 4, "Ferrari S.p.A.", 1000);
    car1.displayCar(); 
    
    Airplane plane1("Airbus A330-300" , "White", 32, "Airbus", 28000, 60.3);
    plane1.displayPlane();

    return 0;
}