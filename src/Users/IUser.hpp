#ifndef IUSER_HPP
#define IUSER_HPP

#include <iostream>
#include <string>

class IUser{
	public:
		virtual void setName(std::string) = 0;
		virtual void setSurname(std::string) = 0;
		virtual void setPhoneNumber(std::string) = 0;
		virtual std::string getName() = 0;
		virtual std::string getSurname() = 0;
		virtual std::string getPhoneNumber() = 0;
		virtual ~IUser(){std::cout << "Usuario destruido" << std::endl;}
};

#endif // IUSER_HPP
