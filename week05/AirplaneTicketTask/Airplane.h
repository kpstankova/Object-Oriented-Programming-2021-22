#ifndef AIRPLANE_H
#define AIRPLANE_H
//It is good to include all needed libraries for the class implementation in the header file 
//When yu include the header in the cpp file the libraries will be read too
#include<iostream>
#include <cstring>
#include "Person.h"
class AirplaneTicket
{
private:
    char *startingPoint;
    char *endPoint;
    char date[16];
    double price;
    int flightSeat;
    int duration;
    bool bussinesClass; // if true it is bussines else it is economy
    Person holder;

    void copy(const AirplaneTicket& other);
    void erase();

public:
    AirplaneTicket();
    AirplaneTicket(const char *, const char *, const char *, double, int, int, bool);
    AirplaneTicket(const AirplaneTicket &other);
    AirplaneTicket &operator=(const AirplaneTicket &other);
    ~AirplaneTicket();

    const char *getStartingPoint() const;
    const char *getEndPoint() const;
    const char *getDate() const;
    double getPrice() const;
    int getFlightSeat() const;
    int getDuration() const;
    bool getBusinessClass() const;

    int getHolderAge() const;

    void setStartingPoint(const char *startingPoint);
    void setEndPoint(const char *endPoint);
    void setDate(const char *date);
    void setPrice(double price);
    void setFlightSeat(int flightSeat);
    void setDuration(int duration);
    void setBussinesClass(bool bussinesClass);

    void fillTicketInformation();
	void changeDate(const char* date, double price, bool businessClass);
	void printTicket() const;

    const char* getHolderFirstName() const;
	const char* getHolderSurname() const;
	const char* getHolderFamilyName() const;
	void changePerson(const Person& second);
};
#endif // AIRPLANE_H