#ifndef FITNESS_H_INCLUDED
#define FITNESS_H_INCLUDED
#include "Client.h"

class Fitness {
private:
    char * name;
    size_t size;
    size_t capacity;
    Client* clients;

    void copy(const Fitness&);
    void erase();
    void resize();

public:
    Fitness();
    Fitness(const char*, size_t);
    Fitness(const Fitness&);
    Fitness& operator=(const Fitness&);
    ~Fitness();

    void addClient(const Client&);
    void removeClient(const char* );

    void updateClientWeight(const char*, float);
};
#endif //FITNESS_H_INCLUDED