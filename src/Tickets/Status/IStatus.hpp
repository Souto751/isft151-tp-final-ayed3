#ifndef ISTATUS_HPP
#define ISTATUS_HPP

#include <iostream>

class IStatus
{
    public:
    virtual std::string getStatusString() = 0;
    ~IStatus(){std::cout << "Status destruido" << std::endl;}
};

#endif // ISTATUS_HPP