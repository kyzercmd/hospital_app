#pragma once
#include <string>
class blooddonor {
protected:
	int id;
	std::string name;
	int age;
	std::string sex;
	std::string address;
	std::string contact;
	std::string bloodType;
	
public:
	blooddonor(int id, std::string name, int age, std::string sex, std::string address, std::string contact, std::string bloodType);

	int getId();
	std::string getName();
	int getAge();
	std::string getSex();
	std::string getAddress();
	std::string getContact();
	std::string getBloodType();
};