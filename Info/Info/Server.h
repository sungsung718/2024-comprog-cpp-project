#pragma once
#include "Database.h"

class Server {
public:
	Server(std::string filename);
	~Server();
	void createItem(Info& item);
	Info readItem(int id);
	std::vector<Info>& readAll();
	void updateItem(Info& item);
	void deleteItem(int id);
private:
	Database database;
};