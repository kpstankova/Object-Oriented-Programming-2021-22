#include "Emplyee.h"

void Employee::copy(const Employee &other){
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->age = other.age;
    this->salary = other.salary;
}

void Employee::erase(){
    delete[] this->name;
}

Employee::Employee(){
    setName("");
    setAge(0);
    setSalary(0);
}

Employee::Employee(const char *name, int age, float salary){
    setName(name);
    setAge(age);
    setSalary(salary);
}

Employee::Employee(const Employee& other){
    this->copy(other);
}

Employee::~Employee(){
    this->erase();
}

Employee& Employee::operator=(const Employee& other){
    if(this != &other){
        this->erase();
        this->copy(other);
    }
    return *this;
}

void Employee::setName(const char* name){ 
    int size = strlen(name);
    try{
        for(int i = 0; i < size; i++){
            if((name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' || name[i] > 'z')){
                throw "Invalid name!";
            }
        }
        this->erase();
        this->name = new char[size] + 1;
        strcpy(this->name, name);
    }
    catch(const char* message){
        std::cout << message << std::endl;
        this->name = new char[8];
        strcpy(this->name, "unknown");
    }

    
}

void Employee::setAge(int age){
    try{
        if(age < 14 || age >= 65){
            throw "Invalid age!";
        }
        this->age = age;
    }
    catch (const char* message){
        std::cout << message << std::endl;
        this->age = 0;
    }

}

void Employee::setSalary(float salary){
     try{
        if(salary < 0){
            throw "Invalid salary!";
        }
        this->salary = salary;
    }
    catch (const char* message){
        std::cout << message << std::endl;
        this->salary = 0;
    }
}

const char* Employee::getName() const{
    return this->name;
}
int Employee::getAge() const{
    return this->age;
}
float Employee::getSalary() const{
    return this->salary;
}

