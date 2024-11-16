#pragma once
#include <string>

class View {
public:
	virtual void display() = 0;
private:
	std::string instruction;
};