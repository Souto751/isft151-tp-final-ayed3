#ifndef IUPDATE_HPP
#define IUPDATE_HPP

#include <iostream>

class IUpdate
{
    public:
    virtual void setDescription(std::string) = 0;
    virtual std::string getDescription() = 0;
    ~IUpdate(){std::cout << "Update destruida" << std::endl;}
};

#endif // IUPDATE_HPP