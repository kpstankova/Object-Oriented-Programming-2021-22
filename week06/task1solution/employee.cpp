#include "employee.h"

void Employee::copy(const Employee &other) {
  if (name != nullptr) {
    erase();
  }
  setName(other.name);
  setAge(other.age);
  setSalary(other.salary);
}

void Employee::erase() {
  delete[] name;
}

Employee::Employee() {
  setName("Unknown");
  setAge(14);
  setSalary(0);
}

Employee::Employee(const Employee &other) {
  copy(other);
}

Employee &Employee::operator=(const Employee &other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

Employee::~Employee() {
  erase();
}

char *Employee::getName() const {
  return name;
}

int Employee::getAge() const {
  return age;
}

double Employee::getSalary() const {
  return salary;
}

void Employee::setName(const char *n) {
  int length = strlen(n);
  if (length == 0) {
    throw "Invalid name";
  }
  for (int i = 0; i < length; ++i) {
    if ((n[i] < 'a' || n[i] > 'z') && (n[i] < 'A' || n[i] > 'Z') && n[i] != ' ') {
      throw "The name has to contain only letters (a-zA-Z) and whitespace ' '";
    }
  }
  name = new char[length + 1];
  strcpy(name, n);
}

void Employee::setAge(int a) {
  if (a < 14 || a > 70) {
    throw "Age has to be between 14 and 70";
  }
  age = a;
}

void Employee::setSalary(double s) {
  if (s < 0) {
    throw "Salary has to positive number";
  }
  salary = s;
}
