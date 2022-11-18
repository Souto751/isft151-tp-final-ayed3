#ifndef GESTORTICKETS_HPP
#define GESTORTICKETS_HPP


#include <queue>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "../Ticket.cpp"

#include "../Status/Open.cpp"
#include "../../../lib/json.hpp"
#include "../Status/Close.cpp"
#include "../Status/InProcess.cpp"
#include "../../Users/IUser.hpp"
#include "../../ScreenCleaner/ScreenCleaner.cpp"

using namespace nlohmann;

class GestorTickets
{
    public:
    GestorTickets();
    void generateTicketReport(Ticket);
    void listTickets();
    int getNewId();
    Ticket createTicket(IUser*, IUser*);
    void modifyTicket(Ticket);
    void deleteTicket(Ticket);
    void readTicket(Ticket);
    void saveTickets();
    void from_json(json& j, Ticket& r);
    void to_json(json& j, Ticket& r);
    ~GestorTickets();

    private:
    std::vector<Ticket> tickets;
    // Vector o cola?
};

#endif // GESTORTICKETS_HPP