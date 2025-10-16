#include "hospital.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "styles.h"

hospital::hospital() {
	staffs.push_back(staff::staff(1, "staff1", "staff1"));
	staffs.push_back(staff::staff(2, "staff2", "staff2"));
	admins.push_back(admin::admin("admin1", "admin1"));
}

int hospital::loginMenu() {
	setConsoleColor(13);
	clearScreen();
	std::cout << "===================== LOGIN =====================" << std::endl << std::endl;
	std::string username;
	std::string password;
	setConsoleColor(7);
	std::cout << "Enter username: \n->";
	std::getline(std::cin, username);
	std::cout << "Enter password: \n->";
	std::getline(std::cin, password);

	bool found = false;
	
	for (auto& user : admins) {
		if (user.authenticate(username, password) == "admin") {
			setConsoleColor(2);
			std::cout << std::endl << "admin log in successful." << std::endl << std::endl;
			pause();
			found = true;                      
			adminPanel();
			return 0;
		}
	}

	for (auto& user : staffs) {
		if (user.authenticate(username, password) == "staff") {
			setConsoleColor(2);
			std::cout << std::endl << "staff log in successful." << std::endl << std::endl;
			pause();
			found = true;
			staffPanel();
			return 0;
		}
	}
	if (!found) {
		setConsoleColor(12);
		std::cout << std::endl << "invalid credentials." << std::endl << std::endl;
		
		pause();
		clearScreen();
		return -1;
	}
}

void hospital::mainMenu() {
	clearScreen();
	while (true) {
		setConsoleColor(13);
		std::cout << "===================== WELCOME =====================" << std::endl << std::endl;
		setConsoleColor(14);
		std::cout << "1. User login" << std::endl << "2. Staff/Admin login" << std::endl << std::endl;
		setConsoleColor(7);
		std::cout << "Enter choice (1-2): " << std::endl;
		std::cout << "->";
		int choice;
		do { std::cin >> choice; } while (choice < 1 || choice > 2);
		std::cin.ignore();
		if (choice == 1) userPanel();
		else if (choice == 2) loginMenu();

	}
}

void hospital::userPanel() {
	
	while (true) {
		clearScreen();
		setConsoleColor(10);
		std::cout << "===================== USER PANEL =====================" << std::endl << std::endl;
		setConsoleColor(14);
		std::cout << "1. Register Patient\n" << "2. Check patient status\n" << "3. Look for blood donor\n" << "4. Get help\n" << "5. Back" << std::endl << std::endl;
		setConsoleColor(7);
		std::cout << "Enter choice (1-5): " << std::endl;
		std::cout << "->";
		int choice;
		do { std::cin >> choice; } while (choice > 5 || choice < 1);
		std::cin.ignore();
		if (choice == 1) registerPatient();
		else if (choice == 2) patientStatus();
		else if (choice == 3) searchBloodDonor();
		else if (choice == 4) getHelp();
		else if (choice == 5) mainMenu();
	}
}

void hospital::staffPanel() {
	
	while (true) {
		clearScreen();
		setConsoleColor(11);
		std::cout << "===================== STAFF PANEL =====================" << std::endl << std::endl;
		setConsoleColor(14);
		std::cout << "1. Show all patients\n" << "2. Modify patient status\n" << "3. Register blood donor\n" << "4. Delete blood donor\n" << "5. logout" << std::endl << std::endl;
		setConsoleColor(7);
		std::cout << "Enter choice (1-5): " << std::endl;
		std::cout << "->";
		int choice;
		do { std::cin >> choice; } while (choice > 5 || choice < 1);
		std::cin.ignore();
		if (choice == 1) showAllPatients();
		else if (choice == 2) modifyPatientStatus();
		else if (choice == 3) registerBloodDonor();
		else if (choice == 4) deleteBloodDonor();
		else if (choice == 5) mainMenu();
	}
}

void hospital::adminPanel() {
	
	while (true) {
		clearScreen();
		setConsoleColor(12);
		std::cout << "===================== ADMIN PANEL =====================" << std::endl << std::endl;
		setConsoleColor(14);
		std::cout << "1. View all staff accounts\n" << "2. Create staff account\n" << "3. Delete staff account\n" << "4. Update hospital info\n" << "5. logout" << std::endl << std::endl;
		setConsoleColor(7);
		std::cout << "Enter choice (1-5): " << std::endl;
		std::cout << "->";
		int choice;
		do { std::cin >> choice; } while (choice > 5 || choice < 1);
		std::cin.ignore();
		if (choice == 1) viewAllStaff();
		else if (choice == 2) createStaff();
		else if (choice == 3) deleteStaff();
		else if (choice == 4) updateHospitalInfo();
		else if (choice == 5) mainMenu();
	}
}

int hospital::nextPatientId = 1000;
void hospital::registerPatient() {
	clearScreen();
	setConsoleColor(10);
	std::cout << "===================== USER PANEL =====================" << std::endl << std::endl;
	int age, priority;
	std::string name, sex, condition, bloodType, contact;
	setConsoleColor(7);
	std::cout << "Enter name:\n->";
	std::getline(std::cin, name);

	std::cout << "Contact number:\n->";
	std::getline(std::cin, contact);

	std::cout << "Age:\n->";
	std::cin >> age;
	std::cin.ignore();

	std::cout << "Sex:\n->";
	std::getline(std::cin, sex);
	
	std::cout << "Condition:\n->";
	std::getline(std::cin, condition);

	std::cout << "Blood type:\n->";
	std::getline(std::cin, bloodType);

	std::cout << "Priority (1-3)\n->";
	std::cin >> priority;
	std::cin.ignore();

	patient newPatient(nextPatientId++, contact, name, age, sex, condition, priority, bloodType);
	patients.push_back(newPatient);

	setConsoleColor(2);
	std::cout << std::endl << "Patient registered successfully. ID: " << newPatient.getId() << std::endl << std::endl;
	pause();

}

void hospital::patientStatus() {
	clearScreen();
	setConsoleColor(10);
	std::cout << "===================== USER PANEL =====================" << std::endl << std::endl;
	setConsoleColor(7);
	int id;
	bool found = false;
	std::cout << "Enter patient ID:\n->";
	std::cin >> id;
	std::cin.ignore();

	for (auto& patient : patients) {
		if (patient.getId() == id) {
			setConsoleColor(2);
			std::cout << std::endl;
			std::cout << "Found patients: " << std::endl << std::endl;
			setConsoleColor(3);
			std::cout << "ID: " << patient.getId() << std::endl;
			std::cout << "Name: " << patient.getName() << std::endl << "Age: " << patient.getAge() << std::endl << "Sex: " << patient.getSex() << std::endl << "Condition: "
				<< patient.getCondition() << std::endl << "BloodType: " << patient.getBloodType() << std::endl << "Priority: "
				<< patient.getPriority() << std::endl << "Contact: " << patient.getContact() << std::endl << "Status: " << patient.getStatus() << std::endl;

			found = true;
			break;
		}
	}
	if (found) {
		std::cout << std::endl;
		pause();
	}
	else {
		setConsoleColor(12);
		std::cout << std::endl << "Patient not found." << std::endl << std::endl;
		pause();

	}
}

void hospital::showAllPatients() {

	clearScreen();
	setConsoleColor(11);
	std::cout << "===================== STAFF PANEL =====================" << std::endl << std::endl;
	setConsoleColor(2);
	std::cout << "All patients: " << std::endl << std::endl;
	setConsoleColor(3);
	for (auto& patient : patients) {
		std::cout << "ID: " << patient.getId() << std::endl;
		std::cout << "Name: " << patient.getName() << std::endl << "Age: " << patient.getAge() << std::endl << "Sex: " << patient.getSex() << std::endl << "Condition: "
			<< patient.getCondition() << std::endl << "Blood Group: " << patient.getBloodType() << std::endl << "Priority: "
			<< patient.getPriority() << std::endl << "Contact: " << patient.getContact() << std::endl << "Status: " << patient.getStatus() << std::endl << std::endl;
	}
	std::cout << std::endl;
	pause();
}

void hospital::searchBloodDonor() {
	clearScreen();
	setConsoleColor(10);
	std::cout << "===================== USER PANEL =====================" << std::endl << std::endl;
	setConsoleColor(7);
	std::cout << "Blood group: " << std::endl;
	std::string search;
	std::getline(std::cin, search);
	bool found = false;
	setConsoleColor(2);
	std::cout << "Blood donors with " << search << ": " << std::endl << std::endl;
	setConsoleColor(3);
	for (auto& it : bloodDonors) {
		
		if (it.getBloodType() == search) {
			found = true;
			std::cout << "ID: " << it.getId() << std::endl << "Name: " << it.getName() << std::endl << "Age: " << it.getAge() << std::endl << "Sex: " << it.getSex() << std::endl << "Address: "
				<< it.getAddress() << std::endl << "Contact: " << it.getContact() << std::endl << "Blood Group:" << it.getBloodType() << std::endl << std::endl;
		}

	}
	if (found) pause();
	else {
		setConsoleColor(12);
		std::cout << std::endl << "No matches." << std::endl;
		pause();
	}
}

void hospital::getHelp() {
	clearScreen();
	std::cout << "===================================================================" << std::endl;
	std::cout << "In case of emergency, call our 24 / 7 hotline immediately: " << std::endl;
	std::cout << "Emergency Number : " << getEmergencyNum() << std::endl;
	std::cout << "Ambulance service: Available 24/7 inside the city" << std::endl << std::endl;
	std::cout << "For non urgent questions, feedback, or appointment related help :" << std::endl;
	std::cout << "Email: " << getEmail() << std::endl;
	std::cout << "Phone: " << getQueriesNum() << std::endl;
	std::cout << "Working Hours: Saturday - Thursday, 9:00 AM - 8:00 PM" << std::endl;
	std::cout << "===================================================================" << std::endl << std::endl;
	pause();
}

int hospital::nextDonorId = 2000;
void hospital::registerBloodDonor() {
	clearScreen();
	setConsoleColor(11);
	std::cout << "===================== STAFF PANEL =====================" << std::endl << std::endl;
	setConsoleColor(7);
	
	std::string name;
	int age;
	std::string sex;
	std::string address;
	std::string contact;
	std::string bloodType;

	std::cout << "Enter name: \n->";
	std::getline(std::cin, name);

	std::cout << "Age: \n->";
	std::cin >> age;
	std::cin.ignore();

	std::cout << "Sex: \n->";
	std::getline(std::cin, sex);

	std::cout << "Address: \n->";
	std::getline(std::cin, address);

	std::cout << "Contact: \n->";
	std::getline(std::cin, contact);

	std::cout << "Blood Type: \n->";
	std::getline(std::cin, bloodType);

	blooddonor donor(nextDonorId++, name, age, sex, address, contact, bloodType);
	bloodDonors.push_back(donor);

	setConsoleColor(2);
	std::cout << "Donor registered successfully. ID: " << donor.getId() << std::endl << std::endl;
	pause();
}

void hospital::deleteBloodDonor() {
	clearScreen();
	setConsoleColor(11);
	std::cout << "===================== STAFF PANEL =====================" << std::endl << std::endl;
	setConsoleColor(7);
	std::cout << "Enter name: \n->";
	std::string search;
	bool nameFound = false;
	std::getline(std::cin, search);
	std::transform(search.begin(), search.end(), search.begin(), ::tolower);
	setConsoleColor(3);
	for (auto it = bloodDonors.begin(); it != bloodDonors.end(); it++) {
		std::string donorName = it->getName();
		std::transform(donorName.begin(), donorName.end(), donorName.begin(), ::tolower);
		if (donorName.find(search) != std::string::npos) {
			nameFound = true;
			std::cout << "ID: " << it->getId() << std::endl << "Name: " << it->getName() << std::endl << "Age: " << it->getAge() << std::endl << "Sex: " << it->getSex() << std::endl << "Address: "
				<< it->getAddress() << std::endl << "Contact: " << it->getContact() << std::endl << "Blood Group:" << it->getBloodType() << std::endl << std::endl;
		}
	}
	if (nameFound) {
		setConsoleColor(7);
		std::cout << "Type id of donor to delete: \n->";
		int del;
		std::cin >> del;
		std::cin.ignore();
		bool idFound = false;

		for (auto it = bloodDonors.begin(); it != bloodDonors.end();) {
			int id = it->getId();
			if (del == id) {
				idFound = true;
				it = bloodDonors.erase(it);
				setConsoleColor(2);
				std::cout << "Deleted successfully. ID: " << id << std::endl << std::endl;
				pause();
			}
			else {
				++it;
			}
		}
		if (!idFound) {
			setConsoleColor(12);
			std::cout << "ID not found." << std::endl << std::endl;
			pause();
		}
	}
	else {
		setConsoleColor(12);
		std::cout << "Name not found." << std::endl << std::endl;
		pause();
	}
}

void hospital::modifyPatientStatus() {
	clearScreen();
	setConsoleColor(11);
	std::cout << "===================== STAFF PANEL =====================" << std::endl << std::endl;
	setConsoleColor(7);
	std::cout << "Enter name: \n->";
	std::string search;
	bool nameFound = false;
	std::getline(std::cin, search);
	std::transform(search.begin(), search.end(), search.begin(), ::tolower);
	setConsoleColor(3);
	for (auto it = patients.begin(); it != patients.end(); it++) {
		std::string patientName = it->getName();
		std::transform(patientName.begin(), patientName.end(), patientName.begin(), ::tolower);
		if (patientName.find(search) != std::string::npos) {
			nameFound = true;
			std::cout << "ID: " << it->getId() << std::endl;
			std::cout << "Name: " << it->getName() << std::endl << "Age: " << it->getAge() << std::endl << "Sex: " << it->getSex() << std::endl << "Condition: "
				<< it->getCondition() << std::endl << "Blood Group: " << it->getBloodType() << std::endl << "Priority: "
				<< it->getPriority() << std::endl << "Contact: " << it->getContact() << std::endl << "Status: " << it->getStatus() << std::endl << std::endl;
		}
	}

	if (nameFound) {
		setConsoleColor(7);
		std::cout << "Type id of Patient to modify status: \n->";
		int modify;
		std::cin >> modify;
		std::cin.ignore();
		bool idFound = false;

		for (auto it = patients.begin(); it != patients.end(); it++) {
			int id = it->getId();
			if (modify == id) {
				idFound = true;
				std::cout << "Change status to: \n->";
				std::string newStatus;
				std::getline(std::cin, newStatus);
				it->setStatus(newStatus);
				setConsoleColor(2);
				std::cout << "Changed successfully." << std::endl << std::endl;
				pause();
				break;
			}
			
		}
		if (!idFound) {
			setConsoleColor(12);
			std::cout << "ID not found." << std::endl << std::endl;
			pause();
		}
	}
	else {
		setConsoleColor(12);
		std::cout << "Name not found." << std::endl << std::endl;
		pause();
	}
}

// admin

void hospital::viewAllStaff() {

	clearScreen();
	setConsoleColor(12);
	std::cout << "===================== ADMIN PANEL =====================" << std::endl << std::endl;
	setConsoleColor(2);
	std::cout << "All active staff accounts: \n" << std::endl << std::endl;
	setConsoleColor(3);
	for (auto& account : staffs) {
		std::cout << account.getId()<< ". " << std::endl;
		std::cout << "Username: " << account.getUsername() << std::endl << "Password: " << account.getPassword() << std::endl << std::endl;
	}
	pause();
}

int hospital::nextAccount = 3;
void hospital::createStaff() {

	clearScreen();
	setConsoleColor(12);
	std::cout << "===================== ADMIN PANEL =====================" << std::endl << std::endl;
	setConsoleColor(7);
	std::cout << "Username: \n->";
	std::string username;
	std::string password;
	std::getline(std::cin, username);

	std::cout << "Password: \n->";
	std::getline(std::cin, password);


	staff newStaff(nextAccount++, username, password);
	staffs.push_back(newStaff);

	setConsoleColor(2);
	std::cout << "Staff account added successfully. ID: " << newStaff.getId() << std::endl << std::endl;
	pause();
}

void hospital::deleteStaff() {
	clearScreen();
	setConsoleColor(12);
	std::cout << "===================== ADMIN PANEL =====================" << std::endl << std::endl;
	viewAllStaff();
	setConsoleColor(7);
	std::cout << "Enter number to delete: \n->";
	int del;
	std::cin >> del;
	std::cin.ignore();
	bool foundId = false;

	for (auto it = staffs.begin(); it != staffs.end();) {
		int id = it->getId();
		if (del == id) {
			foundId = true;
			it = staffs.erase(it);
			setConsoleColor(2);
			std::cout << "Deleted successfully." << std::endl << std::endl;
			pause();
		}
		else ++it;
	}

	if (!foundId) {
		setConsoleColor(12);
		std::cout << "ID not found." << std::endl << std::endl;
		pause();
	}
}

void hospital::setEmergencyNum(std::string emergencyNum) {
	this->emergencyNum = emergencyNum;
}
void hospital::setEmail(std::string email) {
	this->email = email;
}
void hospital::setQueriesNum(std::string queriesNum) {
	this->queriesNum = queriesNum;
}
std::string hospital::getEmergencyNum() {
	return this->emergencyNum;
}
std::string hospital::getQueriesNum() {
	return this->queriesNum;
}
std::string hospital::getEmail() {
	return this->email;
}

void hospital::updateHospitalInfo() {
	clearScreen();
	setConsoleColor(12);
	std::cout << "===================== ADMIN PANEL =====================" << std::endl << std::endl;
	setConsoleColor(14);
	std::cout << "1. Update Emergency Number." << std::endl << "2. Update Non urgent number." << std::endl << "3. Update Email." << std::endl << std::endl;
	setConsoleColor(7);
	std::cout << "Enter choice: (1-3)" << std::endl;
	int choice;
	std::cin >> choice;
	std::cin.ignore();
	if (choice > 3 || choice < 1) {
		setConsoleColor(12);
		std::cout << "Invalid choice." << std::endl;
		pause();
	}
	else {
		if (choice == 1) {
			std::string newNum;
			setConsoleColor(7);
			std::cout << "New number: \n->";
			std::getline(std::cin, newNum);
			setEmergencyNum(newNum);
			setConsoleColor(2);
			std::cout << "Emergency Number changed successfully." << std::endl << std::endl;
			pause();
		}
		else if (choice == 2) {
			std::string newNum;
			setConsoleColor(7);
			std::cout << "New number: \n->";
			std::getline(std::cin, newNum);
			setQueriesNum(newNum);
			setConsoleColor(2);
			std::cout << "Non urgent number changed successfully." << std::endl << std::endl;
			pause();
		}
		else if (choice == 3) {
			std::string newEmail;
			setConsoleColor(7);
			std::cout << "New email: \n->";
			std::getline(std::cin, newEmail);
			setEmail(newEmail);
			setConsoleColor(2);
			std::cout << "Email changed successfully." << std::endl << std::endl;
			pause();
		}
	}
}