#ifndef INPROCESS_HPP
#define INPROCESS_HPP

#include "IStatus.hpp"

class InProcess : public IStatus
{
    public:
    InProcess();
    std::string getStatusString();
    ~InProcess();

    private:
    std::string status;
};

#endif // INPROCESS_HPP