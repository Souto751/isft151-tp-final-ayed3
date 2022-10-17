#ifndef GESTORUSERS_HPP
#define GESTORUSERS_HPP

#include <string>
#include "IUser.hpp"
#include "Client.cpp"

class GestorUsers{
	public:
		GestorUsers();
		bool login(std::string, std::string);
		bool registerUser();
		bool logout();
		~GestorUsers();
	private:
		IUser *user;
};

#endif // GESTORUSERS_HPP
