#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <cstring>

class Employee{
private:
    char* name;
    int age;
    float salary;

    void copy(const Employee& other);
    void erase();
public:
    Employee();
    Employee(const char* name, int age, float salary);
    Employee(const Employee& other);
    ~Employee();

    Employee& operator=(const Employee& other);

    void setName(const char* name);
    void setAge(int age);
    void setSalary(float salary);

    const char* getName() const;
    int getAge() const;
    float getSalary() const;
};

#endif