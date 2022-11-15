
#include "Open.hpp"

Open::Open()
{
    std::cout << "Open Status creado" << std::endl;
    this->status = "Open";
}

std::string Open::getStatusString()
{
    return this->status;
}

Open::~Open()
{
    std::cout << "Open Status destruido" << std::endl;
}

