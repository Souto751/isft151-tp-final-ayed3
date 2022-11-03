
#include "Ticket.hpp"

Ticket::Ticket()
{
    std::cout << "Ticket creado" << std::endl;
}

void Ticket::setId(int _id)
{
    this->id = _id;
}

void Ticket::setRequest(std::string _request)
{
    this->request = _request;
}

void Ticket::setClient(IUser* _client)
{
    this->client = _client;
}

void Ticket::setAsistente(IUser* _asistente)
{
    this->asistente = _asistente;
}

void Ticket::setStatus(IStatus* _status)
{
    this->status = _status;
}

void Ticket::addComment(IUpdate* _comment)
{
    comments.push_back(_comment);
}

void Ticket::addQuestion(IUpdate* _question)
{
    questions.push_back(_question);
}

int Ticket::getId()
{
    return this->id;
}

std::string Ticket::getRequest()
{
    return this->request;
}

IUser* Ticket::getClient()
{
    return this->client;
}

IUser* Ticket::getAsistente()
{
    return this->asistente;
}

IStatus* Ticket::getStatus()
{
    return this->status;
}

IUpdate* Ticket::getComments()
{
    for (int i = 0; i < comments.size(); i++)
    {
        std::cout << comments[i]->getDescription() << std::endl;
    }
}

IUpdate* Ticket::getQuestions()
{
    for (int i = 0; i < questions.size(); i++)
    {
        std::cout << questions[i]->getDescription() << std::endl;
    }
}

Ticket::~Ticket()
{
    std::cout << "Ticket destruido" << std::endl;
}
