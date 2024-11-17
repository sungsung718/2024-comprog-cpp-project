#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Info.h"

namespace print_utils {
	void printSummaryHeader(const std::vector<std::pair<std::string, int>>& field_length);
	void printSummaryBody(Info& info, const std::vector<std::pair<std::string, int>>& field_length);
	void printSummaryBodyField(const std::string& field, int length);
};