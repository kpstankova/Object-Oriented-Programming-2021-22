#pragma once
#include <cstring>

class Employee {
private:
  char *name;
  int age;
  double salary;

private:
  void copy(const Employee &);
  void erase();

public:
  Employee();
  Employee(const Employee &);
  Employee &operator=(const Employee &);
  ~Employee();

  char *getName() const;
  int getAge() const;
  double getSalary() const;

  void setName(const char *);
  void setAge(int);
  void setSalary(double salary);
};