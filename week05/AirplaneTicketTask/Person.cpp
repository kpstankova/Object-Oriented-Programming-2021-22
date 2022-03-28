#include "Person.h"

void Person::erase() {
    delete[] this->firstName;
    delete[] this->surname;
    delete[] this-> familyName;
}

void Person::copy(const Person& other) {
    setFirstName(other.firstName);
    setSurname(other.surname);
    setFamilyName(other.familyName);
    setEgn(other.egn);
    setAge(other.age);
}

Person::Person() {
    setFirstName("");
    setSurname("");
    setFamilyName("");
    setEgn(0);
    setAge(0);
}

Person::Person(const char * firstName, const char* surname, const char* familyName, int egn, int age) {
    setFirstName(firstName);
    setSurname(surname);
    setFamilyName(familyName);
    setEgn(egn);
    setAge(age);
}

Person::Person(const Person& other) {
    copy(other);
}

Person& Person::Person::operator=(const Person& other) {
    if(this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

const char* Person::getFirstName() const {
	return firstName;
}

const char* Person::getSurname() const {
	return surname;
}

const char* Person::getFamilyName() const {
	return familyName;
}

int Person::getEgn() const {
	return egn;
}

int Person::getAge() const {
	return age;
}

void Person::setFirstName(const char* firstName) {
	delete[] this->firstName;
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
}

void Person::setSurname(const char* surname) {
	delete[] this->surname;
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
}

void Person::setFamilyName(const char* familyName) {
	delete[] this->familyName;
    this->familyName = new char[strlen(familyName) + 1];
    strcpy(this->familyName, familyName);
}

void Person::setEgn(int egn) {
	this->egn = egn;
}

void Person::setAge(int age) {
	this->age = age;
}