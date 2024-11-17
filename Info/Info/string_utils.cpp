#include "string_utils.h"
#include <algorithm>

std::string string_utils::to_lower(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
	return str;
}

std::string& string_utils::trim(std::string& str) {
	str.erase(str.find_last_not_of(" \t\n\r") + 1);
	str.erase(0, str.find_first_not_of(" \t\n\r"));
	return str;
}

std::vector<std::string> string_utils::split(std::string str, const char delimiter) {
	std::vector<std::string> result;
	std::string token;
	for (char c : str) {
		if (c == delimiter) {
			result.push_back(token);
			token.clear();
		}
		else {
			token += c;
		}
	}
	result.push_back(token);
	return result;
}

bool string_utils::is_number(const std::string& str) {
	return !str.empty() && std::all_of(str.begin(), str.end(), [](unsigned char c) { return std::isdigit(c); });
}