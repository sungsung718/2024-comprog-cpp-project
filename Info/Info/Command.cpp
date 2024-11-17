#include "Command.h"

State InvalidCommand::execute() {
	std::cout << Message::INVALID_INPUT << std::endl;
	return current_state;
}

State QuitCommand::execute() {
	std::cout << Message::EXIT_PROGRAM << std::endl;
	return State::Quit;
}

State HomeCommand::execute() {
	SummaryView view{ server.readAll() };
	view.display();
	return State::Home;
}

State ReadCommand::execute() {
	DetailView view { server.readItem(id) };
	view.display();
	return State::Detail;
}

State CreateCommand::execute() {
	wait_command = WaitCreateInputCommand{};
	wait_command.execute();

	// get input
	std::string input;
	getline(std::cin, input);
	std::vector<std::string> input_vector;
	input_vector = string_utils::split(input, ';');

	// create info object
	Info info{input_vector};
	confirm_command = ConfirmSaveAfterCreateCommand{};
	confirm_command.execute();

	// get confirmation as y/n
	getline(std::cin, input);
	input = string_utils::to_lower(input);
	if (input == "n") {
		return State::Home;
	}
	if (input == "y") {
		save_command = SaveAfterCreateCommand{ info, server };
		return save_command.execute();
	}

	return State::Invalid;
}

State WaitCreateInputCommand::execute() {
	CreateView view{};
	view.display();
	return State::WaitingCreateInput;
}

State ConfirmSaveAfterCreateCommand::execute() {
	CreateView view{};
	view.confirmCreate();
	return State::WaitingCreateConfirm;
}

State SaveAfterCreateCommand::execute() {
	server.createItem(info);
	return State::Home;
}