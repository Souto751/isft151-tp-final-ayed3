#ifndef OPEN_HPP
#define OPEN_HPP

#include "IStatus.hpp"

class Open : public IStatus
{
    public:
    Open();
    std::string getStatusString();
    ~Open();

    private:
    std::string status;
};

#endif // OPEN_HPP