#include "company.h"

void Company::copy(const Company& other) {
  capacity = other.capacity;
  size = other.size;
  employees = new Employee[capacity];
  for (int i = 0; i < size; ++i) {
    employees[i] = other.employees[i];
  }
}

void Company::erase() {
  delete[] employees;
}

Company::Company() {
  capacity = 16;
  size = 0;
  employees = new Employee[capacity];
}

Company::Company(const Company& other) {
  copy(other);
}

Company& Company::operator=(const Company& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

Company::~Company() {
  erase();
}

void Company::addEmployee(const Employee& newEmployee) {
  if (size >= capacity) {
    throw "Not enough space for one more employee";
  }
  employees[size++] = newEmployee;
}

const Employee& Company::getMostPaid() const {
  int index = 0;
  for (int i = 1; i < size; ++i) {
    if (employees[index].getSalary() < employees[i].getSalary()) {
      index = i;
    }
  }

  return employees[index];
}

void Company::saveEmployees(const char* fileName) {
  std::ofstream ofs;
  ofs.open(fileName);
  if (!ofs) {
    throw "File not opened";
  }
  ofs << capacity << std::endl;
  ofs << size << std::endl;
  for (int i = 0; i < size; ++i) {
    ofs << employees[i].getName() << "%" << employees[i].getAge() << "%" << employees[i].getSalary() << std::endl;
  }
}
