#include "person.h"
#include <exception>

void Person::copy(const Person& other) {
    setName(other.name);
    setId(other.id);
}

void Person::erase() {
    delete[] this->name;
}

Person::Person() {
    setName("Unknown");
    setId("0000000000");
}

Person::Person(const Person& other) {
    copy(other);
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

Person::~Person() {
    erase();
}

Person::Person(const char* name, const char* id) {
    setName(name);
    setId(id);
}

void Person::setName(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Person::setId(const char* id) {
    strcpy(this->id, id);
}

const char* Person::getName() const {
    return this->name;
}

const char* Person::getId() const {
    return this->id;
}
