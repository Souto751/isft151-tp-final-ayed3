#include <iostream>
#include <cstdlib>
#include "./menu.hpp"

Menu::Menu(){
    this->g_notifications = new GestorNotifications();
    this->g_users = new GestorUsers();
    this->g_tickets = new GestorTickets();
}

void Menu::listOptions(){
    if(this->g_users->isLogged()){
        std::cout << "Sistema de Tickets" << std::endl << std::endl;
        std::cout << "1. Crear Ticket" << std::endl;
        std::cout << "2. Ver información de un Ticket" << std::endl;
        std::cout << "3. Ver lista de Tickets" << std::endl;
        std::cout << "4. Modificar Ticket" << std::endl;
        std::cout << "5. Eliminar Ticket" << std::endl;
        std::cout << "6. Ver notificaciones" << std::endl;
        std::cout << "7. Cerrar Sesión" << std::endl;
    }else{
        std::cout << "Usuario no logueado. Por favor seleccione una de las siguientes opciones: " << std::endl << std::endl;
        std::cout << "1. Iniciar Sesión" << std::endl;
        std::cout << "2. Registrarse" << std::endl;
        std::cout << "99. Salir" << std::endl;
    }
}

bool Menu::selectOption(){
    std::cout << "Ingrese opción: ";
    try{
        std::cin >> this->option;
    }catch(int _opt){
        std::cout << "\nOpción incorrecta." << std::endl << std::endl;
        this->option = NULL;
        system("pause");
        return false;
    }

    if(this->g_users->isLogged()){
        if(this->option <= 0 || this-> option > 7){
            std::cout << "Opción incorrecta." << std::endl << std::endl;
            this->option = NULL;
            system("pause");
            return false;
        }else{
            return true;
        }
    }else{
        if(this->option != 1 && this->option != 2 && this->option != 99){
            std::cout << "Opción incorrecta." << std::endl << std::endl;
            this->option = NULL;
            system("pause");
            return false;
        }else{
            return true;
        }
    }
}

void Menu::doAction(){
    if(this->option == 1){
        // MODIFICAR EL METODO PARA PASARLE SOLAMENTE EL OBJETO USUARIO
        // this->g_tickets->createTicket(this->g_users->getUser());
    }else if(this->option == 2){
        // MOSTRAR LA LISTA DE LOS TICKETS CON SU ID, PARA LUEGO SELECCIONAR EL QUE SE QUIERE MOSTRAR
        // AGREGAR FUNCION PARA OBTENER TICKET PASANDO ID
        // this->g_tickets->readTicket(this->g_tickets->getTicket(id));
    }else if(this->option == 3){
        // MOSTRAR LA LISTA DE LOS TICKETS
    }else if(this->option == 4){
        // MOSTRAR LA LISTA DE LOS TICKETS CON SU ID, PARA LUEGO SELECCIONAR EL QUE SE QUIERE MODIFICAR
        // AGREGAR FUNCION PARA OBTENER TICKET PASANDO ID
        // this->g_tickets->modifyTicket(this->g_tickets->getTicket(id));
    }else if(this->option == 5){
        // MOSTRAR LA LISTA DE LOS TICKETS CON SU ID, PARA LUEGO SELECCIONAR EL QUE SE QUIERE ELIMINAR
        // AGREGAR FUNCION PARA OBTENER TICKET PASANDO ID
        // this->g_tickets->deleteTicket(this->g_tickets->getTicket(id));
    }else if(this->option == 6){
        // MOSTRAR LA LISTA DE NOTIFICACIONES DEL USUARIO
        // this->g_notifications->listNotifications();
    }
    system("pause");
}

bool Menu::noUser(){
    std::cin.clear();
    fflush(stdin);
    if(this->option == 1){
        this->login();
        this->option = NULL;
    }else if(this->option == 2){
        this->registerUser();
        this->option = NULL;
    }else if(this->option == 99){
        return false;
    }
    return true;
}

void Menu::login(){
    std::string user = "";
    std::string password = "";

    clean_screen();
    std::cout << "Iniciar Sesión" << std::endl << std::endl;
    std::cout << "Usuario: ";
    getline(std::cin, user);
    std::cout << "Constraseña: ";
    getline(std::cin, password);
    if(user == "" || password == ""){
        std::cout << "Error, hay uno o varios campos vacíos." << std::endl;
        system("pause");
    }else{
        if(!this->g_users->login(user, password)){
            std::cout << "Usuario y/o contraseña inválido." << std::endl;
            system("pause");
        }
    }
}

void Menu::logout(){
    this->g_users->logout();
}

void Menu::registerUser(){
    std::string user = "";
    std::string password = "";
    std::string conf_password = "";

    clean_screen();
    std::cout << "Iniciar Sesión" << std::endl << std::endl;
    std::cout << "Usuario: ";
    getline(std::cin, user);
    std::cout << "Constraseña: ";
    getline(std::cin, password);
    std::cout << "Confirmar Constraseña: ";
    getline(std::cin, conf_password);

    if(password != conf_password){
        std::cout << "Las contraseñas no coinciden." << std::endl;
        system("pause");
    }else if(user == "" || password == "" || conf_password == ""){
        std::cout << "Error, hay uno o varios campos vacíos." << std::endl;
        system("pause");
    }else{
        if(!this->g_users->registerUser(user, password)){
            std::cout << "Error al crear usuario." << std::endl;
            system("pause");
        }
    }
}

void Menu::run(){
    clean_screen();
    this->listOptions();

    
    if(this->selectOption()){
        if(this->g_users->isLogged()){

            // AGREGAR MÉTODOS PARA QUE SE RELLENEN TANTO LOS TICKETS COMO LAS NOTIFICACIONES
            // DE ACUERDO AL USUARIO QUE SE LOGUEO

            if(this->option == 7){
                this->logout();
            }else{
                this->doAction();
            }
            this->option = NULL;
        }else{
            if(!this->noUser()){
                return;
            }
            this->option = NULL;
        }
    }

    this->run();
}

Menu::~Menu(){
    delete this->g_notifications;
    delete this->g_users;
    delete this->g_tickets;
}