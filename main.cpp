#include <iostream>
#include <cstdlib>
#include "./src/Users/Gestor/GestorUsers.cpp"
#include "./src/Tickets/Gestor/GestorTickets.cpp"
#include "./src/Notifications/Gestor/GestorNotifications.cpp"

int main(){
	GestorUsers * g_users = new GestorUsers();
	IUser* client1 = g_users->login("example user", "password");
	IUser* asistente1 = g_users->loginAsistente("example asistente", "pass");

	GestorTickets* g_tickets = new GestorTickets();
	Ticket newTicket1 = g_tickets->createTicket(123456, client1, asistente1);
	Ticket newTicket2 = g_tickets->createTicket(654231, client1, asistente1);
	// g_tickets->readTicket(newTicket);
	g_tickets->listTickets();
	


	delete client1;
	delete asistente1;
	delete g_users;
	delete g_tickets;
	system("pause");
	return 0;
}
