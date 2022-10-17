#include <GestorNotifications.hpp>

GestorNotifications::GestorNotifications(){
	std::cout << "Gestor creado" << std::endl;
}

bool GestorNotifications::createNotification(std::string _desc, std::string _type){
    INotification * notif = NULL;
    if(_type == "alert"){
        notif = new Alert();
    }else if(_type == "query"){
        notif = new Query();
    }

    if(notif != NULL){
        notif->setNotification(_desc);
    }

    this->notifications.push_back(notif);
	std::cout << "Notificacion creada" << std::endl;
	return true;
}

void GestorNotifications::listNotifications(){
	std::list<INotification*>::iterator it;
	int i = 1;
	for (it = this->notifications.begin(); it != this->notifications.end(); ++it){
		std::cout << i++ << ": " << (*it)->getNotification() << std::endl;
	}
}

GestorNotifications::~GestorNotifications(){
	std::list<INotification*>::iterator it;
    for (it = this->notifications.begin(); it != this->notifications.end(); ++it){
		delete * it;
	}
	std::cout << "Gestor destruido" << std::endl;
}
