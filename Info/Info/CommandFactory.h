#pragma once
#include "Command.h"
#include "string_utils.h"

class CommandFactory {
public:
	CommandFactory(Server& server) : server{ server } {}
	Command create_command(std::string input, State current_state);
private:
	Server server;
};