#ifndef ASISTENTE_HPP
#define ASISTENTE_HPP

#include "../IUser.hpp"

class Asistente : public IUser
{
    public:
        Asistente();
        void setName(std::string);
	    void setSurname(std::string);
	    void setPhoneNumber(std::string);
	    std::string getName();
        std::string getRole();
	    std::string getSurname();
	    std::string getPhoneNumber();
        ~Asistente();
    private:
        std::string name, surname, phoneNumber;

};

#endif // ASISTENTE_HPP