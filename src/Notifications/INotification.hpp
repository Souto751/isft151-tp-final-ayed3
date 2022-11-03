#ifndef INOTIFICATION_HPP
#define INOTIFICATION_HPP

#include <iostream>
#include <string>

class INotification{
	public:
		virtual void setNotification(std::string) = 0;
		virtual std::string getNotification() = 0;
		~INotification(){std::cout << "Notificacion destruida" << std::endl;}
};

#endif // INOTIFICATION_HPP
