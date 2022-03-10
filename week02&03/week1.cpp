#include <iostream>
#include <cstring>

enum Genders
{
  dummy = 0,
  Male,
  Female
};

struct Doctor
{
  char lastname[32];
  int yearsExperience;
  char hospital[32];
  Genders gender;

  void createDoctor()
  {
    int userInput;

    std::cout << "Enter name: ";
    std::cin.getline(lastname, 32);
    std::cout << "Enter years experience: ";
    std::cin >> yearsExperience;
    std::cout << "Enter hospital: ";
    std::cin.ignore();
    std::cin.getline(hospital, 32);
    std::cout << "Enter gender(1- male, 2-female): ";
    std::cin >> userInput;
    gender = getDoctorGender(userInput);
    std::cin.ignore();
    std::cout << std::endl;
  }
  Genders getDoctorGender(int userInput)
  {
    switch (userInput)
    {
    case 1:
      return Male;
    case 2:
      return Female;

    default:
      return dummy;
    }
  }

  void printDoctorInfo()
  {
    std::cout << "Name: " << lastname << std::endl;
    std::cout << "Years experience: " << yearsExperience << std::endl;
    std::cout << "Hospital: " << hospital << std::endl;
    std::cout << "Gender: " << gender << std::endl;
  }

  void changeName()
  {
    std::cout << "Enter new name: ";
    std::cin.getline(lastname, 32);
  }

  void changeHospital()
  {
    std::cout << "Enter new hospital: ";
    std::cin.getline(hospital, 32);
  }
};

int main()
{
  Doctor doctors[3];
  for (int i = 0; i < 3; i++)
  {
    doctors[i].createDoctor();
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (doctors[i].yearsExperience > doctors[j].yearsExperience)
      {
        std::swap(doctors[i], doctors[j]);
      }
    }
  }

  for (int i = 0; i < 3; i++)
  {
    doctors[i].printDoctorInfo();
  }
}