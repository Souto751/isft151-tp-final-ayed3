#include "Asistente.hpp"

Asistente::Asistente()
{
    std::cout << "Asistente creado" << std::endl;
}

void Asistente::setName(std::string _name){
	this->name = _name;
}

void Asistente::setSurname(std::string _surname){
	this->surname = _surname;
}

void Asistente::setPhoneNumber(std::string _phone){
	this->phoneNumber = _phone;
}

std::string Asistente::getName(){
	return this->name;
}

std::string Asistente::getSurname(){
	return this->surname;
}

std::string Asistente::getPhoneNumber(){
	return this->phoneNumber;
}

Asistente::~Asistente(){
	std::cout << "Asistente destruido" << std::endl;
}
