#include "View.h"

void SummaryView::display() {
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