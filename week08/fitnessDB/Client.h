#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <cstddef>
#include<iostream>
#include<cstring>

class Client {
private:
    char * name;
    size_t age;
    float weight;

    void copy(const Client& other);
    void erase();
public:
    Client();
    Client(const char*, size_t, float);
    Client(const Client&);
    Client& operator=(const Client&);
    ~Client();

    void setWeight(float weight);

    const char * getName() const;
};

#endif