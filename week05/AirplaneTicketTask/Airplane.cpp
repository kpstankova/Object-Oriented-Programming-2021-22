#include "Airplane.h"

//private function to use into the Destructor, keeping the encapsulation
//we are deleting the memory only for the dynamically allocated memory
void AirplaneTicket::erase() {
    delete[] this->startingPoint;
    delete[] this->endPoint;
}

//private function to use into the copy constructor and operator=, keeping the encapsulation
void AirplaneTicket::copy(const AirplaneTicket& other) {
    //setting other object values to the current object
    setStartingPoint(other.startingPoint);
    setEndPoint(other.endPoint);
    setDate(other.date);
    setPrice(other.price);
    setFlightSeat(other.flightSeat);
    setDuration(other.duration);
    setBussinesClass(other.bussinesClass);
}

AirplaneTicket::AirplaneTicket() {
    //giving default values to the setters for the default constructor
    setStartingPoint("");
    setEndPoint("");
    setDate("");
    setPrice(0.0);
    setFlightSeat(1);
    setDuration(150);
    setBussinesClass(true);
}

AirplaneTicket::AirplaneTicket(const char *startingPoint, const char *endPoint, const char *date, double price, int flightSeat, int duration, bool businessClass) {
    setStartingPoint(startingPoint);
    setEndPoint(endPoint);
    setDate(date);
    setPrice(price);
    setFlightSeat(flightSeat);
    setDuration(duration);
    setBussinesClass(bussinesClass);
}

AirplaneTicket &AirplaneTicket::operator=(const AirplaneTicket &other) {
    //checkoing if the pointer of the current object is pointed to the object we want to copy
    if (this != &other){
        //first we delete the old memory allocated for this object
        this->erase();
        //then create the new one same as the other
        this->copy(other);
    }
    //we return pointer to the current object
    return *this;
}

AirplaneTicket::~AirplaneTicket() {
    erase();
}

//GETTERS

const char* AirplaneTicket::getStartingPoint() const {
	return startingPoint;
}

const char* AirplaneTicket::getEndPoint() const {
	return endPoint;
}

double AirplaneTicket::getPrice() const {
	return price;
}

int AirplaneTicket::getFlightSeat() const {
	return flightSeat;
}

int AirplaneTicket::getDuration() const {
	return duration;
}

bool AirplaneTicket::getBusinessClass() const {
	return bussinesClass;
}

//SETTERS

void AirplaneTicket::setStartingPoint(const char* startingPoint) {
    //deleting the memory to ensure that there is nothing pointing there already
    delete[] this->startingPoint;
    //allocating memory for the char array, as much as we need
    this->startingPoint = new char[strlen(startingPoint) + 1];
    //copying the memory from the local variable to the current object variable
    strcpy(this->startingPoint, startingPoint);
    //for VisualStudio ----> strcpy_s(this->startingPoint, strlen(startingPoint) + 1, startingPoint);
}

void AirplaneTicket::setEndPoint(const char* endPoint) {
    delete[] this->endPoint;
    this->endPoint = new char[strlen(endPoint) + 1];
    strcpy(this->endPoint, endPoint);
}

void AirplaneTicket::setDate(const char* date) {
    //only coping the memory from the local variable to the current object variable because it is not dynamically allocated
    strcpy(this->date, date);
}

void AirplaneTicket::setPrice(double price) {
    //only assigning the value of the local variable to the object variable because it is int
    this->price = price;
}

void AirplaneTicket::setFlightSeat(int flightSeat) {
    this->flightSeat = flightSeat;
}

void AirplaneTicket::setDuration(int duration) {
    this->duration = duration;
}

void AirplaneTicket::setBussinesClass(bool bussinesClass) {
    this->bussinesClass = bussinesClass;
}

void AirplaneTicket::fillTicketInformation() {
    //entering values from the console
    char * startingPoint, *endPoint;
    char date[16];
    double price;
    int flightSeat, duration;
    bool businessClass;
    std::cout << "Enter starting point: ";
	std::cin.getline(startingPoint, strlen(startingPoint) + 1);
	std::cout << "Enter end point: ";
    std::cin.getline(endPoint, strlen(endPoint) + 1);
	std::cout << "Enter date: ";
	std::cin.getline(date, 16);
	std::cout << "Enter price: ";
	std::cin >> price;
	std::cout << "Enter flight seat: ";
	std::cin >> flightSeat;
	std::cout << "Enter duration: ";
	std::cin >> duration;
	std::cout << "Enter business class(1 - for business, 0 - for economy): ";
	std::cin >> bussinesClass;
    //calling the constructor to create the new object with the provided values
    AirplaneTicket(startingPoint, endPoint, date, price, flightSeat, duration, bussinesClass);

    char * firstName, *surname, *familyName;
    int egn, age;
	std::cout << "Enter holder's first name: ";
	std::cin.getline(firstName, strlen(firstName) + 1);
	std::cout << "Enter holder's surname: ";
	std::cin.getline(surname, strlen(surname) + 1);
	std::cout << "Enter holder's family name: ";
	std::cin.getline(familyName, strlen(familyName) + 1);
	std::cout << "Enter holder's egn: ";
	std::cin >> egn;
	std::cout << "Enter holder's age: ";
	std::cin >> age;

	holder.setFirstName(firstName);
	holder.setSurname(surname);
	holder.setFamilyName(familyName);
	holder.setEgn(egn);
	holder.setAge(age);
}

void AirplaneTicket::printTicket() const {
	std::cout << "The starting point is: " << startingPoint << std::endl;
	std::cout << "The final destination is: " << endPoint << std::endl;
	std::cout << "The date of the flight is: " << date << std::endl;
	std::cout << "The price is: " << price << std::endl;
	std::cout << "The flight seat is: " << flightSeat << std::endl;
	std::cout << "The duration of the flight is: " << duration << std::endl;
	if (bussinesClass) {
		std::cout << "The ticket is for business class." << std::endl;
	}
	else {
		std::cout << "The ticket is for economy class." << std::endl;
	}
	std::cout << "The name of the holder is: " <<
		holder.getFirstName() << " " <<
		holder.getSurname() << " " <<
		holder.getFamilyName() << " " << std::endl;
	std::cout << "The age of th holder is: " << holder.getAge() << std::endl;
	std::cout << "The egn of th holder is: " << holder.getEgn() << std::endl;
}

void AirplaneTicket::changeDate(const char* date, double price, bool businessClass) {
	setDate(date);
	setPrice(price);
	setBussinesClass(businessClass);
}

void AirplaneTicket::changePerson(const Person& other) {
	holder.setFirstName(other.getFirstName());
	holder.setSurname(other.getSurname());
	holder.setFamilyName(other.getFamilyName());
	holder.setEgn(other.getEgn());
	holder.setAge(other.getAge());
}

int AirplaneTicket::getHolderAge() const {
	return holder.getAge();
}


