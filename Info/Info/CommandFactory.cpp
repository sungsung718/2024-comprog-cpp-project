#include "CommandFactory.h"

Command CommandFactory::create_command(std::string input, State current_state) {
	if (current_state == State::Invalid) {
		return InvalidCommand{ current_state };
	}
	
	const std::string input = string_utils::to_lower(input);
	if (input == "q") {
		return QuitCommand{};
	}
	if (input == "h") {
		return HomeCommand{server};
	}
	
	if (current_state == State::Home) {
		if (string_utils::is_number(input)) {
			return ReadCommand{ std::stoi(input), server };
		}
		if (input == "c") {
			return CreateCommand{server};
		}
	}

	return InvalidCommand{ current_state };
}