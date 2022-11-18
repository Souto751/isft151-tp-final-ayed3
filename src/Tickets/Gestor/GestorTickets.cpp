
#include "./GestorTickets.hpp"


GestorTickets::GestorTickets()
{
    std::cout << "Gestor Tickets creado" << std::endl;
}

void GestorTickets::to_json(json& j, Ticket& r) {
    std::string cliente = "", asistente = "";
    json comments = json::array();
    json questions = json::array();

    if(r.getClient() != NULL){
        cliente = r.getClient()->getName();
    }

    if(r.getAsistente() != NULL){
        cliente = r.getAsistente()->getName();
    }

    for(int i = 0; i < r.getCommentsList().size(); i++){
        json c;
        c["comentario"] = r.getCommentsList()[i]->getDescription();
        comments.push_back(c);
    }

    for(int i = 0; i < r.getQuestionsList().size(); i++){
        json q;
        q["pregunta"] =  r.getQuestionsList()[i]->getDescription();
        questions.push_back(q);
    }

    j = json{
        {"id", r.getId()}, 
        {"problema", r.getRequest()}, 
        {"cliente", cliente}, 
        {"asistente", asistente}, 
        {"preguntas", questions},
        {"comentarios", comments}
    };
}

void GestorTickets::from_json(json& j, Ticket& r) {
    /*r.id = j.at("id").get<int>();
    r.name = j.at("name").get<std::string>();
    r.maxPlayers = j.at("maxPlayers").get<int>();
    r.timePerQuestion = j.at("timePerQuestion").get<int>();
    r.isActive = j.at("timePerQuestion").get<int>();*/
}

void GestorTickets::saveTickets(){
    json _ticket;
    json _tickets;

    for(int i = 0; i < this->tickets.size(); i++){
        this->to_json(_ticket, this->tickets[i]);
        _tickets.push_back(_ticket);
    }

    std::ofstream ticket_file;
    ticket_file.open("./db/tickets.json");
    if(ticket_file.good()){
        ticket_file << std::setw(4) << _tickets << std::endl;
    }
    ticket_file.close();

}

void GestorTickets::generateTicketReport(Ticket ticket)
{
    std::cout << "Info de Ticket" << std::endl;
    std::cout << "ID: " << ticket.getId() << std::endl;
    std::cout << "Problema: " << ticket.getRequest() << std::endl;
    if(ticket.getClient() != NULL){
        std::cout << "Cliente: " << ticket.getClient()->getName() << std::endl;
    }
    if(ticket.getAsistente() != NULL){
        std::cout << "Asistente: " << ticket.getAsistente()->getName() << std::endl;
    }
    if(ticket.getStatus() != NULL){
        std::cout << "Estado: " << ticket.getStatus()->getStatusString() << std::endl;
    }
    if(ticket.getComments() != NULL){
        std::cout << "Comentarios: \n" << ticket.getComments()->getDescription() << std::endl;
    }
    if(ticket.getQuestions() != NULL){
        std::cout << "Preguntas: \n" << ticket.getQuestions()->getDescription() << std::endl;
    }
}

void GestorTickets::listTickets()
{
    for (int i = 0; i < tickets.size(); i++)
    {
        std::cout << "Ticket Nro: " << tickets[i].getId() << std::endl;
    }

}

int GestorTickets::getNewId(){
    std::ifstream users_file("./db/users.json");
	if(users_file.good() && !(users_file.peek() == std::ifstream::traits_type::eof())){
		json users;
		users_file >> users;
		users_file.close();
		if(!users.empty()){
            int aux = 0;
			for (auto& element : users) {
				if(users.size() == aux++){
					return element["id"];
				}
			}
		}else{
            return 1;
        }
	}else{
		users_file.close();
        return 1;
	}

    return 1;
}

Ticket GestorTickets::createTicket(IUser* client, IUser* asistente)
{
   clean_screen();
    std::string request;

    std::cout << "Crear Ticket" << std::endl << std::endl;
    std::cout << "Problema: ";
    getline(std::cin, request);

    Ticket ticket;
    ticket.setId(this->getNewId());
    ticket.setClient(client);
    ticket.setAsistente(asistente);
    ticket.setRequest(request);
    ticket.setStatus(new Open());
    this->tickets.push_back(ticket);
    this->saveTickets();

    std::cout << "\n\n-------------------------------\nMostrando Ticket\n-----------------\n\n";
    this->generateTicketReport(ticket);

    // GUARDAR TICKET EN JSON

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

            // REEMPLAZAR STD::CIN CON GETLINE(STD::CIN, VARIABLE)

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
    // Eliminar todos los tickets
    std::cout << "Gestor Tickets destruido" << std::endl;
}