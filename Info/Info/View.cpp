#include "View.h"

void View::displayViewSeparator() {
	std::cout << std::endl << std::string(100, '-') << std::endl << std::endl;
}

void SummaryView::display() {
	displayViewSeparator();
	std::cout << Message::PROGRAM_NAME << std::endl;
	std::cout << Message::SLOGAN << std::endl;
	std::cout << std::endl;

	std::cout << instruction << std::endl;
	std::cout << "c: " << Message::CREATE_INFO << std::endl;
	std::cout << std::endl;
	
	printSummary();
	std::cout << std::endl;

	std::cout << Message::WAIT_INPUT;
}

void SummaryView::printSummary() {
	print_utils::printSummaryHeader(field_length);
	std::cout << std::string(100, '-') << std::endl;
	for (auto& info : info_vector) {
		print_utils::printSummaryBody(info, field_length);
	}
}


void DetailView::display() {
	displayViewSeparator();
	std::cout << Message::PROGRAM_NAME << std::endl;
	std::cout << Message::SLOGAN << std::endl;
	std::cout << std::endl;

	std::cout << info.to_string();
	std::cout << std::endl;

	std::cout << "h: " << Message::RETURN_HOME << std::endl;
	std::cout << std::endl;

	std::cout << Message::WAIT_INPUT;
}


void CreateView::display() {
	displayViewSeparator();
	std::cout << Message::PROGRAM_NAME << std::endl;
	std::cout << Message::SLOGAN << std::endl;
	std::cout << std::endl;

	std::cout << instruction << std::endl;
	std::cout << "h: " << Message::RETURN_HOME << std::endl;
	std::cout << std::endl;

	std::cout << Message::WAIT_INPUT_NEWLINE;
}

void CreateView::confirmCreate() {
	std::cout << std::endl;
	std::cout << Message::GUIDE_SAVE_INFO << std::endl;
	std::cout << Message::WAIT_INPUT;
}