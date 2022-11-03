#ifndef COMMENT_HPP
#define COMMENT_HPP

#include "./IUpdate.hpp"

class Comment : public IUpdate
{
    public:
    Comment();
    void setDescription(std::string);
    std::string getDescription();
    ~Comment();

    private:
    std::string description;


};

#endif // COMMENT_HPP