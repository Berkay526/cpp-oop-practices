#include <iostream>
#include <vector>
#include <string>

// singleton library manager
class LibraryManager {
// set private so that only one instance can be used
private:
    static LibraryManager* instance;
    LibraryManager() {}

public:
    // access method
    static LibraryManager* getInstance() {
        if(!instance) {
            instance = new LibraryManager();
        }
        return instance;
    }

    // library operations
    void borrowBook(const std::string& bookName, const std::string memberName) {
        std::cout << memberName << " has borrowed the book : " << bookName << std::endl;
    }

    void donateBook(const std::string& bookName) {
        std::cout << "The book has been donated : " << bookName << std::endl;
    }

    void returnBook(const std::string& bookName, const std::string memberName) {
        std::cout << memberName << " has returned the book : " << bookName << std::endl;
    }

    void addMember(const std::string memberName) {
        std::cout << "The member has been added : " << memberName << std::endl;
    }

    void removeMember(const std::string memberName) {
        std::cout << "The member has been removed : " << memberName << std::endl;
    }
};

// initialize instance and assign NULL
LibraryManager* LibraryManager::instance = nullptr;

int main() {
    // take the LibraryManager instance
    LibraryManager* library = LibraryManager::getInstance();  

    // perform the operations
    library->addMember("John Doe");
    library->borrowBook("C++ Programming", "John Doe");
    library->returnBook("C++ Programming", "John Doe");
    library->donateBook("Python Essentials");
    library->removeMember("John Doe");
}