#include <iostream>
//classwork
class ISBN {
    int a;
public:
    ISBN() {
        std::cout << "ISBN()" << std::endl;
    }
    ~ISBN() {
        std::cout << "~ISBN()" << std::endl;
    }
};

class Book {
    ISBN isbn;
public:
    Book() : isbn() {
        std::cout << "Book()" << std::endl;
    }
    ~Book() {
        std::cout << "~Book()" << std::endl;
    }
};

class Bag {
    Book book;
public: 
    Bag() : book() {
        std::cout << "Bag()" << std::endl;
    }
    ~Bag() {
        std::cout << "~Bag()" << std::endl;
    }
};

int main() {

    Bag b;

    return 0;
}