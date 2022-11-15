
#include "Comment.hpp"

Comment::Comment()
{
    std::cout << "Comment creado" << std::endl;
}

void Comment::setDescription(std::string description)
{
    this->description = description;
}

std::string Comment::getDescription()
{
    return this->description;
}

Comment::~Comment()
{
    std::cout << "Comment destruida" << std::endl;
}
