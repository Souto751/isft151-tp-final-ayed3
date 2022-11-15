#ifndef GESTORUSERS_HPP
#define GESTORUSERS_HPP

#include <string>
#include <fstream>
#include <iomanip>
#include "../../../lib/json.hpp"
#include "../IUser.hpp"
#include "../Client/Client.cpp"
#include "../Asistente/Asistente.cpp"
using namespace nlohmann;

class GestorUsers{
	public:
		GestorUsers();
		bool login(std::string, std::string);
		IUser* loginAsistente(std::string, std::string);
		bool registerUser(std::string, std::string);
		bool logout();
		bool isLogged();
		IUser* getUser();
		~GestorUsers();
	private:
		IUser *user;
};

#endif // GESTORUSERS_HPP
