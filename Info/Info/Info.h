#pragma once
#include "json.hpp"
#include <string>
#include <unordered_map>
#include "string_utils.h"

using json = nlohmann::json;

class Info {
public:
	Info(
		std::string title,
		std::string author,
		std::string type = "",
		int year = 2024,
		std::string summary = "",
		std::string link = ""
	);

	Info(const json& j);
	Info(std::vector<std::string>& fields, size_t len);

	int getId() const;
	void setId(int id);

	std::string& getTitle();
	void setTitle(std::string& title);

	std::string& getAuthor();
	void setAuthor(std::string& author);

	std::string& getType();
	void setType(std::string& type);

	int getYear() const;
	void setYear(int year);

	std::string& getSummary();
	void setSummary(std::string& summary);

	std::string& getLink();
	void setLink(std::string& link);

	std::string getField(const std::string& key) const;
	void setField(const std::string& key, const std::string& value);
	bool hasField(const std::string& key) const;
	void removeField(const std::string& key);

	size_t size() const;

	json to_json() const;
	std::string to_string() const;

private:
	int id{ 0 };
	std::string title;
	std::string author;
	std::string type;
	int year;
	std::string summary;
	std::string link;
	std::unordered_map<std::string, std::string> fields;
};