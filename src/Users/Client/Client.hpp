#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "../IUser.hpp"

class Client : public IUser{
	public:
		Client();
		void setName(std::string);
		void setSurname(std::string);
		void setPhoneNumber(std::string);
		std::string getName();
		std::string getSurname();
		std::string getPhoneNumber();
		std::string getRole();
		~Client();
	private:
		std::string name, surname, phoneNumber;
};

#endif // CLIENT_HPP
