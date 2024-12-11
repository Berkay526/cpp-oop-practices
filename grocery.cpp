#include <iostream>
#include <string_view>

class Vegetable {
public:
    std::string_view name{};
    double price{};
};

class Customer {
public:
    std::string_view name{};

    void buys(const Vegetable& vegetable) {
        std::cout << name << " buys " << vegetable.name << " and pays " << vegetable.price << " euros." << std::endl;
    }
};

int main(void) {
    Customer John{"John"};
    Vegetable tomatoe{"tomatoe", 2.3};

    John.buys(tomatoe);
}