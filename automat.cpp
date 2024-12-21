#include <iostream>
#include <unordered_map>
#include <string>

class Automat {
private:
    struct Product {
        std::string name;
        double price;
    };

    std::unordered_map<int, Product> m_products;
    int m_numberOfInputs{};
    int m_key{};
    std::string m_name{};
    double m_price{};

public:
    // Constructor
    Automat() {
        std::cout << "Automat created.\n";
    }

    // Destructor
    ~Automat() {
        std::cout << "Automat destroyed.\n";
    }

    // Method to add products
    void addProduct() {
        std::cout << "Enter the number of products you're going to add: ";
        std::cin >> m_numberOfInputs; // Get the number of inputs from the user

        for (int i = 0; i < m_numberOfInputs; ++i) {
            std::cout << "Enter the number the product will be placed: "; 
            std::cin >> m_key; 
            std::cin.ignore(); // Clear the buffer

            std::cout << "Enter name of the product: "; 
            std::getline(std::cin, m_name);

            std::cout << "Enter price of the product: ";
            std::cin >> m_price;

            // Add to hash table
            m_products[m_key] = {m_name, m_price};
        }
    }

    // Method to buy a product
    void buyProduct() {
        std::cout << "Enter the product number you want to buy: ";
        std::cin >> m_key;

        // Check if the key exists
        auto it = m_products.find(m_key);
        if (it != m_products.end()) {
            // Show the product and remove it from the hash table
            std::cout << "You bought: " << it->second.name << " for " << it->second.price << " units.\n";
            m_products.erase(it);
        } else {
            std::cout << "Product not found!\n";
        }
    }

    // Method to display available products
    void displayProducts() {
        if (m_products.empty()) {
            std::cout << "No products available.\n";
        } else {
            std::cout << "Available products:\n";
            for (const auto& product : m_products) {
                std::cout << "Product number: " << product.first 
                          << ", Name: " << product.second.name 
                          << ", Price: " << product.second.price << "\n";
            }
        }
    }
};

int main() {
    Automat automat;
    int choice;

    while (true) {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Add products\n";
        std::cout << "2. Buy product\n";
        std::cout << "3. Display products\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Handle user choice
        switch (choice) {
            case 1:
                automat.addProduct();
                break;
            case 2:
                automat.buyProduct();
                break;
            case 3:
                automat.displayProducts();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
}