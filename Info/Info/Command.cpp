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
	return State::Home;
}

State ReadCommand::execute() {
	SummaryView view{ server.readAll() };
	view.display();
	return State::Detail;
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