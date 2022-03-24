#include <iostream>
#include <cstring>
#include <fstream>
enum Type
{
    DUMMY = 0,
    Dog,
    Cat,
    Rabbit

};
class Animal
{
private:
    Type type;
    char name[20];
    int age;
    char gender;

public:
    void setName(char name[20])
    {
        strcpy(this->name, name);
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setGender(char gender)
    {
        this->gender = gender;
    }
    void setType(Type type)
    {
        this->type = type;
    }

    const char *getName() const
    {
        return this->name;
    }
    int getAge() const
    {
        return this->age;
    }
    char getGender() const
    {
        return this->gender;
    }
    const Type &getType() const
    {
        return this->type;
    }

    Animal()
    {

        setType(DUMMY);
        setName("");
        setAge(0);
        setGender('M');
    }
    Animal(Type type, char name[20], int age, char gender)
    {
        setType(type);
        setName(name);
        setAge(age);
        setGender(gender);
    }
    void AnimalToBinary()
    {
        std::ofstream stream("Animals.dat", std::ios::binary | std::ios::app);
        if (!stream.is_open())
        {
            return;
        }
        if (!stream)
        {
            return;
        }

        stream.write((char *)&type, sizeof(type));
        stream.write(name, sizeof(name));
        stream.write((char *)&age, sizeof(age));
        stream.write((char *)&gender, sizeof(gender));
        stream.close();
    }
    void BinaryToAnimal()
    {
        std::ifstream stream("Animals.dat", std::ios::binary);
        if (!stream.is_open())
        {
            return;
        }
        if (!stream)
        {
            return;
        }

        stream.read((char *)&type, sizeof(type));
        stream.read(name, sizeof(name));
        stream.read((char *)&age, sizeof(age));
        stream.read((char *)&gender, sizeof(gender));
        stream.close();       
    }
    void printAnimal()
    {
        std::cout<< type <<std::endl
                 << name <<std::endl
                 << age  <<std::endl
                 << gender <<std::endl;
    }
};

int main(){
    int type;
    std::cin>>type;
    char name[20];
    std::cin.ignore();
    std::cin.getline(name,20);
    
    int age;
    std::cin>>age;
    char gender;
    std::cin>>gender;
Animal animal((Type)type,name,age,gender);
animal.AnimalToBinary();
Animal animalTest;
animalTest.BinaryToAnimal();
animalTest.printAnimal();


}