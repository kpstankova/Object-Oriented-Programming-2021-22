#include <iostream>

struct Destination
{
    char city[32];
    int kilometers;

    void print() {
        std::cout << city << " " << kilometers << std::endl;
    }
};
  
int main()
{
    //a
    Destination cityA;
    std::cin.getline(cityA.city, 32);
    std::cin >> cityA.kilometers;
    std::cin.ignore();
    
    Destination cityB;
    std::cin.getline(cityB.city, 32);
    std::cin >> cityB.kilometers;
    std::cin.ignore();
    //b
    std::cout << "The distance between " << cityA.city << " and " << cityB.city << " is: ";
    std::cout << cityA.kilometers - cityB.kilometers << std::endl;
    
    //c
    Destination cityC[3];

    //d
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Enter a name: ";
        std::cin.getline(cityC[i].city, 32);
        
        std::cout << "Enter kilometers: ";
        std::cin >> cityC[i].kilometers;

        std::cin.ignore();
    }

    for (int i = 0; i < 3; ++i) {
        cityC[i].print();
    }
    return 0;
}