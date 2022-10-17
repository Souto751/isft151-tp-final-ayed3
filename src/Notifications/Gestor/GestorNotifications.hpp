#ifndef GESTORNOTIFICATIONS_HPP
#define GESTORNOTIFICATIONS_HPP

#include <string>
#include <INotification.hpp>
#include <Alert.cpp>
#include <Query.cpp>
#include <iterator>
#include <list>

class GestorNotifications{
	public:
		GestorNotifications();
		bool createNotification(std::string, std::string);
        void listNotifications();
		~GestorNotifications();
	private:
		std::list<INotification*> notifications;
};

#endif // GESTORNOTIFICATIONS_HPP
