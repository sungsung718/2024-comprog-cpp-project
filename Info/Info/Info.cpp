#include <iostream>
#include "Info.h"

Info::Info(
	std::string title,
	std::string author,
	std::string type,
	int year,
	std::string summary,
	std::string link
) : title{ title },
author{ author },
type{ type },
year{ year },
summary{ summary },
link{ link } {}

Info::Info(const json& j) {
	auto id = j["id"].template get<int>();
	auto title = j["title"].template get<std::string>();
	auto author = j["author"].template get<std::string>();
	auto type = j["type"].template get<std::string>();
	auto year = j["year"].template get<int>();
	auto summary = j["summary"].template get<std::string>();
	auto link = j["link"].template get<std::string>();

	this->id = id;
	this->title = title;
	this->author = author;
	this->type = type;
	this->year = year;
	this->summary = summary;
	this->link = link;

	for (auto& item : j["others"].items()) {
		setField(item.key(), item.value());
	}
}

Info::Info(std::vector<std::string>& fields, int len) {
	if (len < 6) {
		for (int i = 0; i < 6 - len; i++) {
			fields.push_back("");
		}
	}

	title = string_utils::trim(fields[0]);
	author = string_utils::trim(fields[1]);
	type = string_utils::trim(fields[2]);
	
	if (!string_utils::is_number(fields[3])) {
		year = -1;
	}
	else {
		year = std::stoi(fields[3]);
	}

	summary = string_utils::trim(fields[4]);
	link = string_utils::trim(fields[5]);
}

int Info::getId() const{
	return id;
};

void Info::setId(int id) {
	this->id = id;
};

std::string& Info::getTitle() {
	return title;
};

void Info::setTitle(std::string& title) {
	this->title = title;
};

std::string& Info::getAuthor() {
	return author;
};

void Info::setAuthor(std::string& author) {
	this->author = author;
};

std::string& Info::getType() {
	return type;
};

void Info::setType(std::string& type) {
	this->type = type;
};

int Info::getYear() const{
	return year;
};

void Info::setYear(int year) {
	this->year = year;
};

std::string& Info::getSummary() {
	return summary;
};

void Info::setSummary(std::string& summary) {
	this->summary = summary;
};

std::string& Info::getLink() {
	return link;
};

void Info::setLink(std::string& link) {
	this->link = link;
};

// Add or update a field
void Info::setField(const std::string& key, const std::string& value) {
    fields[key] = value;
}

// Get a field value
std::string Info::getField(const std::string& key) const {
    auto it = fields.find(key);
    if (it != fields.end()) {
        return (it->second);
    }
    throw std::out_of_range("Field not found: " + key);
}

// Check if a field exists
bool Info::hasField(const std::string& key) const {
    return fields.find(key) != fields.end();
}

// Remove a field
void Info::removeField(const std::string& key) {
    fields.erase(key);
}

// Get number of fields
size_t Info::size() const {
    return fields.size();
}

json Info::to_json() const{
	json j = {
		{"id", id},
		{"title", title},
		{"author", author},
		{"type", type},
		{"year", year},
		{"summary", summary},
		{"link", link}
	};

	if (fields.empty()) {
		j["others"] = json::array();
	}
	else {
		for (const auto& pair : fields) {
			j["others"][pair.first] = pair.second;
		}
	}
	
	return j;
}

std::string Info::to_string() const {
	std::string result = "ID: " + std::to_string(id) + "\n";
	result += "Title: " + title + "\n";
	result += "Author: " + author + "\n";
	result += "Type: " + type + "\n";
	result += "Year: " + std::to_string(year) + "\n";
	result += "Summary: " + summary + "\n";
	result += "Link: " + link + "\n";

	if (!fields.empty()) {
		for (const auto& pair : fields) {
			result += pair.first + ": " + pair.second + "\n";
		}
	}

	return result;
}
