
#include "Question.hpp"

Question::Question()
{
    std::cout << "Question creada" << std::endl;
}

void Question::setDescription(std::string description)
{
    this->description = description;
}

std::string Question::getDescription()
{
    return this->description;
}

Question::~Question()
{
    std::cout << "Question destruida" << std::endl;
}