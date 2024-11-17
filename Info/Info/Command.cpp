#include "Command.h"

State InvalidCommand::execute() {
	std::cout << Message::INVALID_INPUT << std::endl;
	std::cout << Message::WAIT_INPUT << std::endl;
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

	std::string input;
	getline(std::cin, input);
	input = string_utils::to_lower(input);
	std::unique_ptr<Command> command;

	if (input == "u") {
		Info info = server.readItem(id);
		command = std::make_unique<UpdateCommand>(info, server);
		return command->execute();
	}
	
	if (input == "d") {
		command = std::make_unique<DeleteCommand>(id, server);
		return command->execute();
	}

	if (input == "h") {
		command = std::make_unique<HomeCommand>(server);
		return command->execute();
	}

	command = std::make_unique<InvalidCommand>(State::Detail);
	return command->execute();
}

State DeleteCommand::execute() {
	DeleteView view{ server.readItem(id) };
	view.display();

	std::string input;
	getline(std::cin, input);
	input = string_utils::to_lower(input);
	std::unique_ptr<Command> command;

	if (input == "h") {
		command = std::make_unique<HomeCommand>(server);
		return command->execute();
	}

	if (input == "n") {
		command = std::make_unique<ReadCommand>(id, server);
		return command->execute();
	}

	if (input == "y") {
		server.deleteItem(id);
		std::cout << Message::SUCCESS_DELETE_INFO << std::endl;
		command = std::make_unique<HomeCommand>(server);
		return command->execute();
	}

	command = std::make_unique<InvalidCommand>(State::Delete);
	return command->execute();
}

State UpdateCommand::execute() {
	UpdateView view{ info };
	std::string input;
	std::unique_ptr<Command> command;
	State state{ State::Update };
	do {
		view.display();

		getline(std::cin, input);
		
		if (input == "h" || input == "H") {
			command = std::make_unique<HomeCommand>(server);
			return command->execute();
		}

		std::vector<std::string> input_vector;
		input_vector = string_utils::split(input, ';');
		if (input_vector.size() != 2) {
			command = std::make_unique<InvalidCommand>(State::Update);
			command->execute();
		}
		else {
			for (auto& i : input_vector) {
				i = string_utils::trim(i);
			}
			auto& field = input_vector[0];
			field = string_utils::to_lower(field);
			auto& value = input_vector[1];

			info.setField(field, value);
			server.updateItem(info);
			std::cout << Message::SUCCESS_SAVE_INFO << std::endl;
		}
	} while (state == State::Update);
}

State CreateCommand::execute() {
	std::unique_ptr<Command> command;
	command = std::make_unique<WaitCreateInputCommand>();
	command->execute();

	// get input
	std::string input;
	getline(std::cin, input);
	std::vector<std::string> input_vector;
	input_vector = string_utils::split(input, ';');

	// create info object
	Info info{input_vector, input_vector.size()};
	command = std::make_unique<ConfirmSaveAfterCreateCommand>();
	command->execute();

	// get confirmation as y/n
	getline(std::cin, input);
	input = string_utils::to_lower(input);
	if (input == "n") {
		command = std::make_unique<HomeCommand>(server);
		return command->execute();
	}
	if (input == "y") {
		command = std::make_unique<SaveAfterCreateCommand>(info, server);
		return command->execute();
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
	std::cout << Message::SUCCESS_SAVE_INFO << std::endl;

	SummaryView view{ server.readAll() };
	view.display();
	return State::Home;
}