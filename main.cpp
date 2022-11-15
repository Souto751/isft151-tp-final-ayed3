#include <iostream>
#include <cstdlib>
#include <windows.h>


#include "./src/Menu/menu.cpp"

int main(){

	SetConsoleOutputCP(CP_UTF8);

	/*------GestorUsers * g_users = new GestorUsers();
	--------IUser* client1 = g_users->login("example user", "password");
	--------IUser* asistente1 = g_users->loginAsistente("example asistente", "pass");

	--------GestorTickets* g_tickets = new GestorTickets();
	Ticket newTicket1 = g_tickets->createTicket(123456, client1, asistente1);
	Ticket newTicket2 = g_tickets->createTicket(654231, client1, asistente1);
	// g_tickets->readTicket(newTicket);
	g_tickets->listTickets();

	g_tickets->modifyTicket(newTicket2);

	g_tickets->listTickets();
	


	delete client1;
	delete asistente1;
	delete g_users;
	delete g_tickets;
	system("pause");*/

	Menu * menu = new Menu();

	menu->run();

	delete menu;

	return 0;
}
