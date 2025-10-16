#pragma once
#include <vector>
#include "login.h"
#include "patient.h"
#include "blooddonor.h"
#include <string>

class hospital {
private:
	std::vector<login> staffs;
	std::vector<login> admins;
	std::vector<patient> patients;
	static int nextPatientId;
	std::vector<blooddonor> bloodDonors;
	static int nextDonorId;
	static int nextAccount;

	std::string emergencyNum = "+880 1310000000";
	std::string email = "cityhospital@hotmail.com";
	std::string queriesNum = "+880 1310000000";

public:
	hospital();
	int loginMenu();
	void mainMenu();
	void registerPatient();
	void userPanel();
	void adminPanel();
	void staffPanel();
	void patientStatus(); //undefined
	void showAllPatients();
	void searchBloodDonor();
	void getHelp();
	void registerBloodDonor();
	void deleteBloodDonor();
	void modifyPatientStatus();

	void viewAllStaff();
	void createStaff();
	void deleteStaff();

	void updateHospitalInfo();
	void setEmergencyNum(std::string emergencyNum);
	void setEmail(std::string email);
	void setQueriesNum(std::string queriesNum);

	std::string getEmergencyNum();
	std::string getEmail();
	std::string getQueriesNum();
};

