#pragma once
#include <vector>
#include "json_utils.h"
#include "Info.h"


class Database {
public:
	Database(std::string& filename);
	~Database();

	void insert(Info& item);
	void update(const Info& item);
	void remove(int id);
	std::vector<Info>& getAll();
	Info getItem(int id);
private:
	std::string filename;
	std::vector<Info> info_vector;
	int next_id{ 1 };
	int generateId();
	void load();
	void save();
};