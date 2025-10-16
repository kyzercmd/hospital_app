#pragma once
#include <string>
class patient {
protected:
	int id;
	std::string contact;
	std::string name;
	int age;
	std::string sex;
	std::string condition;
	int priority;
	std::string bloodType;
	std::string status = "unchecked";
public:
	patient(int id, std::string contact, std::string name, int age, std::string sex, std::string condition, int priority, std::string bloodType);

	int getId();
	std::string getContact();
	std::string getName();
	int getAge();
	std::string getSex();
	std::string getCondition();
	int getPriority();
	std::string getBloodType();
	std::string getStatus();

	void setStatus(std::string status);


};