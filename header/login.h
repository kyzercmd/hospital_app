#pragma once
#include <string>;
class login {
protected:
	int id;
	std::string username;
	std::string password;
	std::string role;
public:
	login(int id, std::string username, std::string password);

	std::string authenticate(std::string inputUsername, std::string inputPassword);

	std::string getUsername();
	std::string getPassword();
	std::string getRole();
	int getId();
};
class admin : public login {
public:
	admin(std::string username, std::string password);
};
class staff : public login {
public:
	staff(int id, std::string username, std::string password);
};