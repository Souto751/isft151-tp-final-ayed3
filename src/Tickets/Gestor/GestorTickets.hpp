#ifndef GESTORTICKETS_HPP
#define GESTORTICKETS_HPP


#include <queue>
#include "../Ticket.cpp"

#include "../Status/Open.cpp"
#include "../Status/Close.cpp"
#include "../Status/InProcess.cpp"
#include "../../Users/IUser.hpp"

class GestorTickets
{
    public:
    GestorTickets();
    Ticket generateTicketReport(Ticket);
    void listTickets();
    Ticket createTicket(int, IUser*, IUser*);
    void modifyTicket(Ticket);
    void deleteTicket(Ticket);
    void readTicket(Ticket);
    ~GestorTickets();

    private:
    std::vector<Ticket> tickets;
    // Vector o cola?
};

#endif // GESTORTICKETS_HPP