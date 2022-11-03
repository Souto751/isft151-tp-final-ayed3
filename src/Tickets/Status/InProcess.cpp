
#include "InProcess.hpp"

InProcess::InProcess()
{
    std::cout << "InProcess Status creado" << std::endl;
    this->status = "InProcess";
}

std::string InProcess::getStatusString()
{
    return this->status;
}

InProcess::~InProcess()
{
    std::cout << "In Process Status destruido" << std::endl;
}