#include "print_utils.h"

void print_utils::printSummaryHeader(const std::vector<std::pair<std::string, int>>& field_length) {
	std::cout << std::left;
	for (auto& field : field_length) {
		std::cout << std::setw(field.second) << field.first << "|";
	}
	std::cout << std::endl;
}

void print_utils::printSummaryBody(Info& info, const std::vector<std::pair<std::string, int>>& field_length) {
	auto id = info.getId();
	auto& title = info.getTitle();
	auto& author = info.getAuthor();
	auto& type = info.getType();
	auto& summary = info.getSummary();
	auto& link = info.getLink();

	auto year = info.getYear();
	std::string year_str = (year == 0) ? "" : std::to_string(year);
	

	print_utils::printSummaryBodyField(std::to_string(id), field_length[0].second);
	print_utils::printSummaryBodyField(title, field_length[1].second);
	print_utils::printSummaryBodyField(author, field_length[2].second);
	print_utils::printSummaryBodyField(type, field_length[3].second);
	print_utils::printSummaryBodyField(year_str, field_length[4].second);
	print_utils::printSummaryBodyField(summary, field_length[5].second);
	print_utils::printSummaryBodyField(link, field_length[6].second);

	std::cout << std::endl;
}

void print_utils::printSummaryBodyField(const std::string& field, int length) {
	if (field.length() > length)
		std::cout << std::setw(length) << field.substr(0, length - 3) + "...";
	else
		std::cout << std::setw(length) << field;
	std::cout << "|";
}