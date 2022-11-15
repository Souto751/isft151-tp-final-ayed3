#ifndef GESTORNOTIFICATIONS_HPP
#define GESTORNOTIFICATIONS_HPP

#include <string>
#include "../Alert/Alert.cpp"
#include "../Query/Query.cpp"
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
