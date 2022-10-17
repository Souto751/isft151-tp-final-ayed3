#include "Client.hpp"

Client::Client(){
	std::cout << "Cliente creado" << std::endl;
}

void Client::setName(std::string _name){
	this->name = _name;
}

void Client::setSurname(std::string _surname){
	this->surname = _surname;
}

void Client::setPhoneNumber(std::string _phone){
	this->phoneNumber = _phone;
}

std::string Client::getName(){
	return this->name;
}

std::string Client::getSurname(){
	return this->surname;
}

std::string Client::getPhoneNumber(){
	return this->phoneNumber;
}

Client::~Client(){
	std::cout << "Cliente destruido" << std::endl;
}
