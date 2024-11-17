#include <iostream>
#include "CommandFactory.h"
#include "Info.h"
#include "Server.h"
#include "View.h"

int main() {
	Server server{ "./database.json" };

	CommandFactory commandFactory{ server };
	std::unique_ptr<Command> command = commandFactory.init_command();
	State state = command->execute();

	std::string input;
	while (state != State::Quit) {
		std::getline(std::cin, input);
		command = commandFactory.create_command(input, state);
		state = command->execute();
	}

	return 0;
}