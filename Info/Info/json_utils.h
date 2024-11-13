#pragma once
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>

using json = nlohmann::json;

namespace json_utils {
	json load_json(const std::string& path);
	void dump_json(const std::string& path, const json& j);
};