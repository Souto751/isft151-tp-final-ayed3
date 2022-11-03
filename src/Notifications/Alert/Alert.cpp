#include <iostream>
#include "Alert.hpp"

Alert::Alert(){
    std::cout << "Alerta creada" << std::endl;
}

void Alert::setNotification(std::string _notification){
    this->message = _notification;
}

std::string Alert::getNotification(){
    return this->message;
}

Alert::~Alert(){
    std::cout << "Alerta destruida" << std::endl;
}