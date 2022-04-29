#pragma once
#include <cstring>

class Person {
private:
    char* name;
    char id[11];

    void copy(const Person& other);
    void erase();

public:
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();
    Person(const char* name, const char* id);

    void setName(const char* name);
    void setId(const char* id);

    const char* getName() const;
    const char* getId() const;
};