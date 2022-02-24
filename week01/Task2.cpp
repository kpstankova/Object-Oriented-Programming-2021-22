#include <iostream>

enum Flavours
{
    dummy = 0,
    Chocolate,
    Vanilla,
    Cream,
    Strawberry
};

struct IceCream
{
    int grams;
    double price;
    Flavours flavour;

    void createIceCream()
    {
        int userInput;

        // std::cin.ignore();
        std::cout << "Enter ice cream" << std::endl;
        std::cout << "Enter flavour(1 - chocolate, 2 - vanilla, 3 - cream, 4 - strawberry): ";
        std::cin >> userInput;
        // flavour = (Flavours)(userInput + 1);
        flavour = getIceCreamFlavour(userInput);
        std::cout << "Enter grams: ";
        std::cin >> grams;
        std::cout << "Enter price: ";
        std::cin >> price;
    }

    Flavours getIceCreamFlavour(int input)
    {
        switch(input)
        {
            case 1: 
                return Chocolate;
            case 2:
                return Vanilla;
            case 3: 
                return Cream;
            case 4:
                return Strawberry;
            default: 
                return dummy;
        }
    }

    void print()
    {
        std::cout << "Flavour: " << (Flavours)flavour << std::endl;
        std::cout << "Grams: " << grams << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
    
};

struct IceCreamFactory
{
    IceCream iceCreams[4];

    void getCheapest()
    {
        IceCream cheapest = iceCreams[0];
        for(int i = 1; i < 4; i++)
        {
            if(iceCreams[i].price < cheapest.price)
            {
                cheapest = iceCreams[i];
            }
        }

        cheapest.print();
    }
};

int main() {
    
    IceCreamFactory factory;

    for(int i = 0; i < 4; i++)
    {
        factory.iceCreams[i].createIceCream();
    }

    factory.getCheapest();
    return 0;
}