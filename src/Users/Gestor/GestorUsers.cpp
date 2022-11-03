#include "GestorUsers.hpp"

GestorUsers::GestorUsers(){
	this->user = NULL;
	std::cout << "Gestor creado" << std::endl;
}

IUser* GestorUsers::login(std::string _username, std::string _password){

	// Cin preguntando si es asistente o cliente.
	// If Asistente { this->user = new Asistente();}
	this->user = new Client();
	this->user->setName(_username);
	std::cout << "Usuario logueado: " << this->user->getName() << std::endl;
	return user;
}

IUser* GestorUsers::loginAsistente(std::string _username, std::string _password)
{
	this->user = new Asistente();
	this->user->setName(_username);
	std::cout << "Usuario logueado: " << this->user->getName() << std::endl;
	return user;
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
