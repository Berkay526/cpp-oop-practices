#include <iostream>
#include <string>

class Vehicle {
private:
    std::string name;
    std::string color;
    int age;

public:
    // Vehicle sınıfının kurucusu
    Vehicle(std::string name, std::string color, int age) : name(name), color(color), age(age) {}

    // Vehicle bilgilerini gösteren fonksiyon
    void display() const {
        std::cout << "Name : " << name 
                  << "\nColor : " << color 
                  << "\nAge : " << age 
                  << std::endl;
    }
};

class Car : public Vehicle { // Türetilmiş sınıf
private:
    std::string brand;
    int engineHP;

public:
    // Car sınıfının kurucusu, Vehicle sınıfının kurucusunu çağırıyor
    Car(std::string name, std::string color, int age, std::string brand, int engineHP)
        : Vehicle(name, color, age), brand(brand), engineHP(engineHP) {}

    // Car bilgilerini gösteren fonksiyon
    void displayCar() const {
        display(); // Vehicle sınıfının display fonksiyonunu çağırır
        std::cout << "Brand : " << brand 
                  << "\nEngine HP : " << engineHP 
                  << std::endl;
    }
};

int main() {
    // Car sınıfından bir nesne oluşturuluyor
    Car car1("Ferrari SF90 Spider", "Red", 4, "Ferrari S.p.A.", 1000);
    car1.displayCar(); // Bilgileri göster
    return 0;
}