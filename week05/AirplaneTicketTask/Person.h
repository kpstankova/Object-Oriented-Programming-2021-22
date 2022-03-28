#ifndef PERSON_H_INCLUDE
#define PERSON_H_INCLUDE
#include <iostream>
#include<cstring>

class Person {
private:
	char * firstName;
	char * surname;
	char * familyName;
	int egn;
	int age;

    void erase();
    void copy(const Person& other);

public:
    Person();
    Person(const char *, const char*, const char*, int, int);
    Person(const Person& other);
    Person & operator=(const Person& other);
    ~Person();

	const char* getFirstName() const;
	const char* getSurname() const;
	const char* getFamilyName() const;
	int getEgn() const;
	int getAge() const;

	void setFirstName(const char* firstName);
	void setSurname(const char* surname);
	void setFamilyName(const char* familyName);
	void setEgn(int egn);
	void setAge(int age);
};
#endif //PERSON_H_INCLUDED