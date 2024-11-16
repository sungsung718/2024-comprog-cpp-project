#include "Server.h"

Server::Server(std::string filename) : database{ filename } {}
Server::~Server() {}

void Server::createItem(Info& item) {
	database.insert(item);
}

Info Server::readItem(int id) {
	return database.getItem(id);
}

std::vector<Info>& Server::readll() {
	return database.getAll();
}

void Server::updateItem(Info& item) {
	database.update(item);
}

void Server::deleteItem(int id) {
	database.remove(id);
}
