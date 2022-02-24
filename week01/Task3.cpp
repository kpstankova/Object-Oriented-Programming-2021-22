#include <iostream>

struct Prisoner {
    char name[32];
    int ID;
    int yearsInPrison;

    void print() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << ID << std::endl;
        std::cout << "Years: " << yearsInPrison << std::endl;
    }
};

struct Prison {
    char name[64];
    Prisoner prisoners[4];

    void sortByYears() {
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (prisoners[i].yearsInPrison > prisoners[j].yearsInPrison) {
                    std::swap(prisoners[i], prisoners[j]);
                }
            }
        }
    }
};

void printPrisonInfo(const Prison& prison) {
    std::cout << prison.name << std::endl;
    for (int i = 0; i < 4; ++i) {
        prison.prisoners[i].print();
    }
}

int main() {

    Prison prison;
    std::cin.getline(prison.name, 64);
    for(int i = 0; i < 4; ++i) {
        std::cin.getline(prison.prisoners[i].name, 32);
        std::cin >> prison.prisoners[i].ID;
        std::cin >> prison.prisoners[i].yearsInPrison;
        std::cin.ignore();
    }

    std::cout << "===========\n";

    printPrisonInfo(prison);
    prison.sortByYears();
    printPrisonInfo(prison);

    return 0;
}