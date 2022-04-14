#include "Client.h"

void Client::copy(const Client& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->age = other.age;
    this->weight = other.weight;
}

void Client::erase() {
    delete[] this->name;
}

Client::Client(){
    this->name = new char[1];
	this->name[0] = '\0';
    //this->name = strcpy(this->name, '\0');
    this->age = 0;
    this->weight = 0;
}

Client::Client(const char* name, size_t age, float weight) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
    this->weight = weight;
}

Client::Client(const Client& other) {
    copy(other);
}

Client& Client::operator=(const Client& other) {
    if(this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

Client::~Client() {
    erase();
}

const char* Client::getName() const {
    return this->name;
}

void Client::setWeight(float weight) {
    this-> weight = weight;
}

    