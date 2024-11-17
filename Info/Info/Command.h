#pragma once
#include "Server.h"
#include "State.h"
#include "string_utils.h"
#include "message.h"
#include "View.h"

class Command {
public:
	virtual ~Command() = default;
	virtual State execute() = 0;
};

class InvalidCommand : public Command {
public:
	InvalidCommand(State current_state) : current_state{ current_state } {}
	State execute() override;
private:
	State current_state;
};

class QuitCommand : public Command {
public:
	State execute() override;
};

class HomeCommand : public Command {
public:
	HomeCommand(Server& server) : server{ server } {}
	State execute() override;
private:
	Server& server;
};

class ReadCommand : public Command {
public:
	ReadCommand(int id, Server& server) : id {id}, server{server} {}
	State execute() override;
private:
	int id;
	Server& server;
};

class DeleteCommand : public Command {
public:
	DeleteCommand(int id, Server& server) : id{ id }, server{ server } {}
	State execute() override;
private:
	int id;
	Server& server;
};

class CreateCommand : public Command {
public:
	CreateCommand(Server& server) : server{ server } {}
	State execute() override;
private:
	Server& server;
};

class WaitCreateInputCommand : public Command {
public:
	State execute() override;
};

class ConfirmSaveAfterCreateCommand : public Command {
public:
	State execute() override;
};

class SaveAfterCreateCommand : public Command {
public:
	SaveAfterCreateCommand(Info info, Server& server) : info{info}, server{server} {}
	State execute() override;
private:
	Info info;
	Server& server;
};