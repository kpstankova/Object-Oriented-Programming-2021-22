#include <iostream>
#include "company.h"

int main(){
  Employee emp1;
  try {
    emp1.setName("Ivan Ivanov Ivanov");
    emp1.setAge(22);
    emp1.setSalary(1234.56);
  } catch (const char* msg) {
    std::cout << msg << std::endl;
  }
  
  Employee emp2;
  try {
    emp2.setName("Georgi Georgiev Georgiev");
    emp2.setAge(26);
    emp2.setSalary(2345.67);
  } catch (const char* msg) {
    std::cout << msg << std::endl;
  }
  
  Company company;
  try {
    company.addEmployee(emp1);
    company.addEmployee(emp2);
  } catch (const char* msg) {
    std::cout << msg << std::endl;
  }

  std::cout << "Most paid employee: " << company.getMostPaid().getName() << std::endl;

  try {
    company.saveEmployees("company.txt");
  } catch (const char* msg) {
    std::cout << msg << std::endl;
  }
}