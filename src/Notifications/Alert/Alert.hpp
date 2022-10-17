#ifndef ALERT_HPP
#define ALERT_HPP

#include "../INotification.hpp"

class Alert : public INotification{
	public:
		Alert();
		void setNotification(std::string);
		std::string getNotification();
		~Alert();
	private:
		std::string message;
};

#endif // ALERT_HPP