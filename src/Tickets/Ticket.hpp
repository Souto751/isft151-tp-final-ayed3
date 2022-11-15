#ifndef TICKET_HPP
#define TICKET_HPP

#include <iostream>
#include <vector>
#include "./Status/IStatus.hpp"
#include "./Update/IUpdate.hpp"
#include "../Users/IUser.hpp"

class Ticket
{
    public:
    Ticket();
    void setId(int);
    void setRequest(std::string);
    void setClient(IUser*);
    void setAsistente(IUser*);
    void setStatus(IStatus*);
    void addComment(IUpdate*);
    void addQuestion(IUpdate*);

    int getId();
    std::string getRequest();
    IUser* getClient();
    IUser* getAsistente();
    IStatus* getStatus();
    IUpdate* getComments();
    IUpdate* getQuestions();

    ~Ticket();

    private:
    int id;
    std::string request;
    IUser* client;
    IUser* asistente;
    IStatus* status;
    std::vector<IUpdate*> comments;
    std::vector<IUpdate*> questions;

};

#endif // TICKET_HPP