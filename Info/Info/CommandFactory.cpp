#include "CommandFactory.h"

std::unique_ptr<Command> CommandFactory::init_command() {
	return std::make_unique<HomeCommand>(server);
}

std::unique_ptr<Command> CommandFactory::create_command(std::string raw_input, State current_state) {
	if (current_state == State::Invalid) {
		return std::make_unique<InvalidCommand>(current_state);
	}
	
	const std::string input{ string_utils::to_lower(raw_input) };
	if (input == "q") {
		return std::make_unique<QuitCommand>();
	}
	if (input == "h") {
		return std::make_unique<HomeCommand>(server);
	}
	
	if (current_state == State::Home) {
		if (string_utils::is_number(input)) {
			return std::make_unique<ReadCommand>(std::stoi(input), server);
		}
		if (input == "c") {
			return std::make_unique<CreateCommand>(server);
		}
	}

	return std::make_unique<InvalidCommand>(current_state);
}