#include "GestorUsers.hpp"

GestorUsers::GestorUsers(){
	this->user = NULL;
	std::cout << "Gestor creado" << std::endl;
}

bool GestorUsers::login(std::string _username, std::string _password){
	this->user = new Client();
	this->user->setName(_username);
	std::cout << "Usuario logueado: " << this->user->getName() << std::endl;
	return true;
}

bool GestorUsers::registerUser(){
	std::string _username;
	std::cout << "\nCrear Usuario: ";
	getline(std::cin, _username);
	
	this->user = new Client();
	this->user->setName(_username);
	std::cout << "Usuario registrado: " << this->user->getName() << std::endl;
	return true;
}

bool GestorUsers::logout(){
	delete this->user;
	std::cout << "Usuario deslogueado" << std::endl;
	return true;
}


GestorUsers::~GestorUsers(){
	delete this->user;
	std::cout << "Gestor destruido" << std::endl;
}
