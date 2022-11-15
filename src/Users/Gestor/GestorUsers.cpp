#include "./GestorUsers.hpp"

GestorUsers::GestorUsers(){
	this->user = NULL;
	std::cout << "Gestor creado" << std::endl;
}

bool GestorUsers::login(std::string _username, std::string _password){
	std::ifstream users_file("./db/users.json");
	if(users_file.good() && !(users_file.peek() == std::ifstream::traits_type::eof())){
		json users;
		users_file >> users;
		users_file.close();
		if(!users.empty()){
			for (auto& element : users) {
				if(element["user"] == _username){
					if(element["password"] == _password){
						if(element["role"] == "Cliente"){
							this->user = new Client();
						}else if(element["role"] == "Asistente"){
							this->user = new Asistente();
						}else{
							return false;
						}
						this->user->setName(_username);
						return true;
					}else{
						return false;
					}
				}
			}
		}
	}else{
		users_file.close();
	}
	return false;
}

IUser* GestorUsers::loginAsistente(std::string _username, std::string _password)
{
	this->user = new Asistente();
	this->user->setName(_username);
	std::cout << "Usuario logueado: " << this->user->getName() << std::endl;
	return user;
}

bool GestorUsers::registerUser(std::string _username, std::string _password){

	std::ifstream users_file("./db/users.json");
	bool exists = false;
	json users;
	if(users_file.good() && !(users_file.peek() == std::ifstream::traits_type::eof())){
		users_file >> users;
		users_file.close();
		if(!users.empty()){
			for (auto& element : users) {
				if(element["user"] == _username){
					exists = true;
					break;
				}
			}
		}
	}else{
		users_file.close();
	}

	if(!exists){
		json new_user;
		new_user["user"] = _username;
		new_user["password"] = _password;
		new_user["role"] = "Cliente";
		users.push_back(new_user);

		this->user = new Client();
		this->user->setName(_username);

		std::ofstream users_file_save("./db/users.json");
		if(users_file_save.good()){
			users_file_save << std::setw(4) << users << std::endl; 
		}
		users_file_save.close();
	}else{
		std::cout << "Ya existe el usuario." << std::endl; 
	}

	return !exists;
}

bool GestorUsers::logout(){
	delete this->user;
	this->user = NULL;
	return true;
}

bool GestorUsers::isLogged(){
	return this->user != NULL;
}

IUser* GestorUsers::getUser(){
	return this->user;
}

GestorUsers::~GestorUsers(){
	delete this->user;
	std::cout << "Gestor destruido" << std::endl;
}
