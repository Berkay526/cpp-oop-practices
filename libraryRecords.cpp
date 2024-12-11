#include <iostream>
#include <string>

class Books {
public:
    std::string bookName{};
    int bookID{};
};

class LibMembers {
private:
    int m_memberID{};

public:
    std::string memberName{};
    int borrowYear{};
    int borrowMonth{};
    int borrowDay{};

    void borrows(const Books& book) const {
        std::cout << memberName << " borrows " << book.bookID << " at " 
        << borrowYear << '/' << borrowMonth << '/' << borrowDay << std::endl;
    }

    void setMemberID(int theID) {
        m_memberID = theID;
    }

    void displayMemberID () const {
        std::cout << "The ID of " << memberName << " : " << m_memberID << std::endl;
    }
};

int main(void) {
    LibMembers John;
    John.setMemberID(12645);
    John.memberName = "John";
    John.borrowYear = 2024;
    John.borrowMonth = 06;
    John.borrowDay = 21;

    Books introToChemistry{"Introduction to Chemistry", 69352};

    John.borrows(introToChemistry);
    John.displayMemberID();
}