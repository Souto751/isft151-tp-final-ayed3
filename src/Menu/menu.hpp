#ifndef MENU_HPP
#define MENU_HPP

#include "../Notifications/Gestor/GestorNotifications.cpp"
#include "../Tickets/Gestor/GestorTickets.cpp"
#include "../Users/Gestor/GestorUsers.cpp"
#include "../ScreenCleaner/ScreenCleaner.cpp"

class Menu{
    private:
        int option = NULL;
        GestorTickets * g_tickets = NULL;
        GestorNotifications * g_notifications = NULL;
        GestorUsers * g_users = NULL;

    public:
        Menu();
        void listOptions();
        bool selectOption();
        void run();
        void login();
        void logout();
        void doAction();
        bool noUser();
        void registerUser();
        ~Menu();
};

#endif