#ifndef CLOSE_HPP
#define CLOSE_HPP

#include "IStatus.hpp"

class Close : public IStatus
{
    public:
    Close();
    std::string getStatusString();
    ~Close();

    private:
    std::string status;
};

#endif // CLOSE_HPP