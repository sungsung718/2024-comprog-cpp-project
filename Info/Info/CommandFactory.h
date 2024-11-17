#pragma once
#include <memory>
#include "Command.h"
#include "string_utils.h"

class CommandFactory {
public:
	CommandFactory(Server& server) : server{ server } {}
	std::unique_ptr<Command> init_command();
	std::unique_ptr<Command> create_command(std::string input, State current_state);
private:
	Server server;
};