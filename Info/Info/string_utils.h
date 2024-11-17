#pragma once
#include <cctype>
#include <string>
#include <vector>

namespace string_utils {
	std::string to_lower(std::string str);
	std::string& trim(std::string& str);
	std::vector<std::string> split(std::string str, const char delimiter);
	bool is_number(const std::string& str);
};