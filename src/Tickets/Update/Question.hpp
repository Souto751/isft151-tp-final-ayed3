#ifndef QUESTION_HPP
#define QUESTION_HPP

#include "./IUpdate.hpp"

class Question : public IUpdate
{
    public:
    Question();
    void setDescription(std::string);
    std::string getDescription();
    ~Question();

    private:
    std::string description;


};

#endif // QUESTION_HPP