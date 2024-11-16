#include "json_utils.h"

json json_utils::load_json(const std::string& path) {
	std::ifstream file(path);
	if (!file.is_open()) {
		std::cerr << path << " does not exist." << std::endl;
		return json{};
	}

	json j;
	file >> j;
	return j;
}

void json_utils::dump_json(const std::string& path, const json& j) {
	std::ofstream file(path);
	if (!file.is_open()) {
		std::cerr << "Error opening " << path << std::endl;
		return;
	}

	file << j.dump(4); // 4 is the indent level
	std::cout << "Saved " << path << " successfully." << std::endl;
}
