#include <iostream>
#include <cstdlib>
#include "GestorUsers.cpp"

int main(){
	GestorUsers * g_users = new GestorUsers();
	g_users->login("example user", "password");

	delete g_users;
	system("pause");
	return 0;
}
