#include "Fitness.h"

void Fitness::copy(const Fitness& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->size = other.size;
    this->capacity = other.capacity;
    for (size_t i=0 ; i< size; ++i) {
        this->clients[i] = other.clients[i];
    }
}

void Fitness::erase() {
    delete[] this->name;
    delete[] this->clients;
}

void Fitness::resize() {
    this->capacity *= 2;
    Client * biggerClients = new Client[this->capacity];
    for (size_t i = 0; i < size; i++) {
        biggerClients[i] = clients[i];
    }
    delete[] this->clients;
    this->clients = biggerClients;
}

Fitness::Fitness() {
    this->name = strcpy(this->name, '\0');
    this->size = 0;
    this->capacity = 8;
    this->clients = new Client[this->capacity];
}

Fitness::Fitness(const char* name, size_t capacity) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->size = size;
    this->capacity = capacity;
    this->clients = new Client[this->capacity];
}

Fitness::Fitness(const Fitness& other) {
    copy(other);
}

Fitness& Fitness::operator=(const Fitness& other) {
    if(this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

Fitness::~Fitness() {
    this->erase();
}

void Fitness::addClient(const Client& newClient) {
    if(this->size >= this->capacity) {
        this->resize();
    }

    clients[size++] = newClient;
}

void Fitness::removeClient(const char* clientName) {
    for (size_t i = 0; i < this->size; i++) {
       if(strcmp(clients[i].getName(), clientName) == 0) {
           for (size_t j = i; j < this->size; j++) {
               clients[j] = clients[j+1];
           }
       }
    }

    --this->size;
}

void Fitness::updateClientWeight(const char* clientName, float newWeight) {
    for (size_t i = 0; i < this->size; i++) {
       if(strcmp(clients[i].getName(), clientName) == 0) {
           clients[i].setWeight(newWeight);
       }
    }
}