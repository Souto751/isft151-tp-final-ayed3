#include <iostream>
#include "Query.hpp"

Query::Query(){
    std::cout << "Query creada" << std::endl;
}

void Query::setNotification(std::string _notification){
    this->message = _notification;
}

std::string Query::getNotification(){
    return this->message;
}

Query::~Query(){
    std::cout << "Query destruida" << std::endl;
}