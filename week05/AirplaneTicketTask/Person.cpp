#include "Person.h"

inline void Person::erase() {
    delete[] this->firstName;
    delete[] this->surname;
    delete[] this-> familyName;
}

inline void Person::copy(const Person& other) {
    setFirstName(other.firstName);
    setSurname(other.surname);
    setFamilyName(other.familyName);
    setEgn(other.egn);
    setAge(other.age);
}

inline Person::Person() {
    setFirstName("");
    setSurname("");
    setFamilyName("");
    setEgn(0);
    setAge(0);
}

inline Person::Person(const char * firstName, const char* surname, const char* familyName, int egn, int age) {
    setFirstName(firstName);
    setSurname(surname);
    setFamilyName(familyName);
    setEgn(egn);
    setAge(age);
}

inline Person::Person(const Person& other) {
    copy(other);
}

inline Person& Person::Person::operator=(const Person& other) {
    if(this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

inline const char* Person::getFirstName() const {
	return firstName;
}

inline const char* Person::getSurname() const {
	return surname;
}

inline const char* Person::getFamilyName() const {
	return familyName;
}

inline int Person::getEgn() const {
	return egn;
}

inline int Person::getAge() const {
	return age;
}

inline void Person::setFirstName(const char* firstName) {
	delete[] this->firstName;
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
}

inline void Person::setSurname(const char* surname) {
	delete[] this->surname;
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
}

inline void Person::setFamilyName(const char* familyName) {
	delete[] this->familyName;
    this->familyName = new char[strlen(familyName) + 1];
    strcpy(this->familyName, familyName);
}

inline void Person::setEgn(int egn) {
	this->egn = egn;
}

inline void Person::setAge(int age) {
	this->age = age;
}