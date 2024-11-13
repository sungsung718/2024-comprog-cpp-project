#pragma once
#include <ctime>
#include <string>
#include <unordered_map>

class Info {
public:
	Info(
		std::string title,
		std::string author = "",
		std::string type = "",
		int year = 2024,
		std::string summary,
		std::string link
	);

	int getId();
	void setId(int id);

	std::string& getTitle();
	void setTitle(std::string& title);

	std::string& getAuthor();
	void setAuthor(std::string& author);

	std::string& getType();
	void setType(std::string& type);

	int getYear();
	void setYear(int year);

	std::string& getSummary();
	void setSummary(std::string& summary);

	std::string& getLink();
	void setLink(std::string& link);

	time_t getCreatedAt();
	void setCreatedAt(time_t created_at);

	void setField(const std::string& key, const std::string& value);

	std::string getField(const std::string& key) const;

	bool hasField(const std::string& key) const;

	void removeField(const std::string& key);

	size_t size() const;

private:
	int id{ 0 };
	std::string title;
	std::string author;
	std::string type;
	int year;
	std::string summary;
	std::string link;
	time_t created_at;
	std::unordered_map<std::string, std::string> fields;
};