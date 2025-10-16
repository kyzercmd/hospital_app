#include "patient.h"

patient::patient(int id, std::string contact, std::string name, int age,std::string sex, std::string condition, int priority, std::string bloodType) {
	this->id = id;
	this->contact = contact;
	this->name = name;
	this->age = age;
	this->sex = sex;
	this->condition = condition;
	this->priority = priority;
	this->bloodType = bloodType;
}

int patient::getId() {
	return this->id;
}
std::string patient::getContact() {
	return this->contact;
}
std::string patient::getName() {
	return this->name;
}
int patient::getAge() {
	return this->age;
}
std::string patient::getSex() {
	return this->sex;
}
std::string patient::getCondition() {
	return this->condition;
}
int patient::getPriority() {
	return this->priority;
}
std::string patient::getBloodType() {
	return this->bloodType;
}
std::string patient::getStatus() {
	return this->status;
}

void patient::setStatus(std::string status) {
	this->status = status;
}
