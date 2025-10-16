#include "blooddonor.h"

blooddonor::blooddonor(int id, std::string name, int age, std::string sex, std::string address, std::string contact, std::string bloodType) {
	this->id = id;
	this->name = name;
	this->age = age;
	this->sex = sex;
	this->address = address;
	this->contact = contact;
	this->bloodType = bloodType;
}

int blooddonor::getId() {
	return this->id;
}

std::string blooddonor::getName() {
	return this->name;
}

int blooddonor::getAge() {
	return this->age;
}
std::string blooddonor::getSex() {
	return this->sex;
}

std::string blooddonor::getAddress() {
	return this->address;
}

std::string blooddonor::getContact() {
	return this->contact;
}

std::string blooddonor::getBloodType() {
	return this->bloodType;
}