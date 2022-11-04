
#include "GestorTickets.hpp"


GestorTickets::GestorTickets()
{
    std::cout << "Gestor Tickets creado" << std::endl;
}

Ticket GestorTickets::generateTicketReport(Ticket ticket)
{
    std::cout << "Info de Ticket" << std::endl;
    std::cout << ticket.getId() << std::endl;
    std::cout << ticket.getRequest() << std::endl;
    std::cout << ticket.getClient()->getName() << std::endl;
    std::cout << ticket.getAsistente()->getName() << std::endl;
    std::cout << ticket.getStatus()->getStatusString() << std::endl;
    std::cout << ticket.getComments()->getDescription() << std::endl;
    std::cout << ticket.getQuestions()->getDescription() << std::endl;
}

void GestorTickets::listTickets()
{
    for (int i = 0; i < tickets.size(); i++)
    {
        std::cout << "Ticket Nro: " << tickets[i].getId() << std::endl;
    }

}

Ticket GestorTickets::createTicket(int id, IUser* client, IUser* asistente)
{
    Ticket ticket;
    ticket.setId(id);
    ticket.setClient(client);
    ticket.setAsistente(asistente);
    ticket.setRequest("No request yet.");
    ticket.setStatus(new Open());
    tickets.push_back(ticket);

    return ticket;
}

void GestorTickets::modifyTicket(Ticket ticket)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i].getId() == ticket.getId())
        {
            int newId;
            std::string newClientName, newClientSurname, newClientPhoneNumber;
            std::string newAsistenteName, newAsistenteSurname, newAsistentePhoneNumber;
            std::string newDescriptionEstado;
            std::string newRequest;

            std::cout << "ID Nueva:" << std::endl;
            std::cin >> newId;
            std::cout << "Request Nueva: " << std::endl;
            std::cin >> newRequest;
            std::cout << "Nombre de cliente: " << std::endl;
            std::cin >> newClientName;
            std::cout << "Apellido de cliente: " << std::endl;
            std::cin >> newClientSurname;
            std::cout << "Numero de telefono de cliente: " << std::endl;
            std::cin >> newClientPhoneNumber;
            std::cout << "Nombre de asistente: " << std::endl;
            std::cin >> newAsistenteName;
            std::cout << "Apellido de asistente: " << std::endl;
            std::cin >> newAsistenteSurname;
            std::cout << "Numero de telefono de asistente: " << std::endl;
            std::cin >> newAsistentePhoneNumber;
            std::cout << "Estado del ticket(Open, Close o InProcess): " << std::endl;
            std::cin >> newDescriptionEstado;

            IStatus* status = NULL;

            if (newDescriptionEstado == "Open" || newDescriptionEstado == "open")
            {
                status = new Open();
            }
            else if (newDescriptionEstado == "Close" || newDescriptionEstado == "close")
            {
                status = new Close();
            }
            else if (newDescriptionEstado == "InProcess" || newDescriptionEstado == "inprocess")
            {
                status = new InProcess();
            }
            else
            {
                status = new Open();
            }

            tickets[i].setId(newId);
            tickets[i].setRequest(newRequest);
            tickets[i].setStatus(status);
            
            tickets[i].getClient()->setName(newClientName);
            tickets[i].getClient()->setSurname(newClientSurname);
            tickets[i].getClient()->setPhoneNumber(newClientPhoneNumber);

            tickets[i].getAsistente()->setName(newAsistenteName);
            tickets[i].getAsistente()->setSurname(newAsistenteSurname);
            tickets[i].getAsistente()->setPhoneNumber(newAsistentePhoneNumber);

            std::cout << "Ticket modificado" << std::endl;
        }
    }
}

void GestorTickets::deleteTicket(Ticket ticket)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i].getId() == ticket.getId())
        {
            std::vector<Ticket>::iterator it;
            it = tickets.begin()+i;
            tickets.erase(it);
        }
    }
}

void GestorTickets::readTicket(Ticket ticket)
{
    generateTicketReport(ticket);
}

GestorTickets::~GestorTickets()
{
    std::cout << "Gestor Tickets destruido" << std::endl;
}