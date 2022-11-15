
#include "Close.hpp"

Close::Close()
{
    std::cout << "Close Status creado" << std::endl;
    this->status = "Close";
}

std::string Close::getStatusString()
{
    return this->status;
}

Close::~Close()
{
    std::cout << "Close Status destruido" << std::endl;
}