#pragma once
#include "message.h"
#include "Info.h"
#include "print_utils.h"

class View {
public:
	virtual void display() = 0;
	void displayViewSeparator();
private:
	std::string instruction;
};


class SummaryView : public View {
public:
	SummaryView(std::vector<Info>& info_vector) : info_vector{ info_vector } {};
	void display() override;
private:
	std::string instruction{Message::PRESS_ID};
	std::vector<std::pair<std::string, int>> field_length{
		{"ID", 7},
		{"Title", 13},
		{"Author", 12},
		{"Type", 10},
		{"Year", 8},
		{"Summary", 21},
		{"Link", 22}
	};
	std::vector<Info>& info_vector;
	void printSummary();
};


class DetailView : public View {
public:
	DetailView(Info info) : info{ info } {};
	void display() override;
private:
	std::string instruction{};
	Info info;
};


class DeleteView : public View {
public:
	DeleteView(Info info) : info{ info } {};
	void display() override;
private:
	std::string instruction{ Message::GUIDE_DELETE_INFO };
	Info info;
};


class UpdateView : public View {
public:
	UpdateView(Info& info) : info{ info } {};
	void display() override;
private:
	std::string instruction{ Message::GUIDE_UPDATE_INFO };
	Info& info;
};


class CreateView : public View {
public:
	void display() override;
	void confirmCreate();
private:
	std::string instruction{ Message::GUIDE_CREATE_INFO };
};