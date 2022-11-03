#ifndef QUERY_HPP
#define QUERY_HPP

#include "../INotification.hpp"

class Query : public INotification{
	public:
		Query();
		void setNotification(std::string);
		std::string getNotification();
		~Query();
	private:
		std::string message;
};

#endif // QUERY_HPP