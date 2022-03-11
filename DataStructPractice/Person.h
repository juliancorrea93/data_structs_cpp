#pragma once
#include <iostream>
#include <string>

class Person {
public:
	Person();
	Person(std::string, std::string, int);
	Person(const Person &obj);
	std::string getName() const;
	int getAge() const;
	std::string getAddress() const;
	//~Person();

private:
	std::string name;
	int age;
	std::string address;
};

std::ostream& operator<<(std::ostream& os, Person person);

bool operator==(Person person1, Person person2);