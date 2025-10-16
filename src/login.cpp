#include "login.h"

login::login(int id, std::string username, std::string password) {
	this->id = id;
	this->username = username;
	this->password = password;
}

std::string login::authenticate(std::string inputUsername, std::string inputPassword) {
	if (inputUsername == username && inputPassword == password) {
		return role;
	}
	else return "invalid";
	
}

std::string login::getUsername() {
	return this->username;
}
std::string login::getPassword() {
	return this->password;
}
std::string login::getRole() {
	return this->role;
}
int login::getId() {
	return this->id;
}

admin::admin(std::string username, std::string password) : login(id, username,password) {
	
	this->role = "admin";
}

staff::staff(int id, std::string username, std::string password) : login(id, username, password) {
	
	this->role = "staff";
}
