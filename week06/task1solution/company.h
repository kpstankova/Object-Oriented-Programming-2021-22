#pragma once
#include <fstream>
#include "employee.h"

class Company {
private:
  Employee* employees;
  int size;
  int capacity;

private:
  void copy(const Company&);
  void erase();

public:
  Company();
  Company(const Company&);
  Company& operator=(const Company&);
  ~Company();

  void addEmployee(const Employee&);
  const Employee& getMostPaid() const;
  void saveEmployees(const char*);
};