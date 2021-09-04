#include <iostream>
#include <string>
#include "Person.h"


std::ostream& operator<<(std::ostream& os, Person person) {
	os << "Name: " << person.getName() << ", Age: " << person.getAge() << ", Address: " << person.getAddress();
	return os;
}

bool operator==(Person person1, Person person2) {
	if (person1.getName() == person2.getName() && person1.getAge() == person2.getAge() && person1.getAddress() == person2.getAddress()) {
		return true;
	}
	else {
		return false;
	}
}

Person::Person()
{
	name = "Julian Correa";
	address = "500 SW 130th Terrace Apt A112 Pembroke Pines, FL 33027";
	age = 23;
}

Person::Person(std::string _name, std::string _address, int _age)
{
	name = _name;
	address = _address;
	age = _age;
}

std::string Person::getName()
{
	return name;
}

int Person::getAge()
{
	return age;
}

std::string Person::getAddress()
{
	return address;
}