#include "Database.h"

Database::Database(std::string& filename) : filename{ filename } {
	load();
}

Database::~Database() {
	save();
}

void Database::load() {
	// Load data from file
	json file = json_utils::load_json(filename);
	if (file.empty()) {
		return;
	}

	next_id = file["meta_data"]["last_id"]+1;
	for (auto& it : file["data"]) {
		// Json to Info conversion
		Info info = Info(it);
		info_vector.push_back(info);
	}
}

void Database::save() {
	// Convert Info to Json and save data to file
	json j = {
		{"meta_data", {
			{"last_id", next_id-1},
			{"count", info_vector.size()}
		}},
		{"data", json::array()}
	};

	for (auto& i : info_vector) {
		j["data"].push_back(i.to_json());
	}

	json_utils::dump_json(filename, j);
}

void Database::insert(Info& item) {
	item.setId(generateId());
	info_vector.push_back(item);
}

int Database::generateId() {
	return next_id++;
}

void Database::update(const Info& item) {
	for (auto& i : info_vector) {
		if (i.getId() == item.getId()) {
			i = item;
			break;
		}
	}
	std::cout << item.getId() << "not found" << std::endl;
}

void Database::remove(int id) {
	info_vector.erase(
		std::remove_if(
			info_vector.begin(),
			info_vector.end(),
			[id](Info& i) { return i.getId() == id; }
		),
		info_vector.end()
	);
}

std::vector<Info>& Database::getAll() {
	return info_vector;
}

Info Database::getItem(int id) {
	for (auto& i : info_vector) {
		if (i.getId() == id) {
			return i;
		}
	}
	throw std::out_of_range("Item not found: " + std::to_string(id));
}

