#include <iostream>
#include "Info.h"

Info::Info(
	std::string title="",
	std::string author="",
	std::string type="",
	int year = 2024,
	std::string summary="",
	std::string link=""
) : title{ title },
author{ author },
type{ type },
year{ year },
summary{ summary },
link{ link } {}

static Info from_json(const json& j) {
	Info info;

	auto id = j["id"].template get<int>();
	auto title = j["title"].template get<std::string>();
	auto author = j["author"].template get<std::string>();
	auto type = j["type"].template get<std::string>();
	auto year = j["year"].template get<int>();
	auto summary = j["summary"].template get<std::string>();
	auto link = j["link"].template get<std::string>();

	info.setId(id);
	info.setTitle(title);
	info.setAuthor(author);
	info.setType(type);
	info.setYear(year);
	info.setSummary(summary);
	info.setLink(link);

	for (auto& item : j["others"].items()) {
		info.setField(item.key(), item.value());
	}

	return info;
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

	for (const auto& pair : fields) {
		j["others"][pair.first] = pair.second;
	}

	return j;
}
