#ifndef GESTORUSERS_HPP
#define GESTORUSERS_HPP

#include <string>
#include "../IUser.hpp"
#include "../Client/Client.cpp"
#include "../Asistente/Asistente.cpp"

class GestorUsers{
	public:
		GestorUsers();
		IUser* login(std::string, std::string);
		IUser* loginAsistente(std::string, std::string);
		bool registerUser();
		bool logout();
		~GestorUsers();
	private:
		IUser *user;
};

#endif // GESTORUSERS_HPP
