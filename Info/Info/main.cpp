#include <iostream>
#include "Info.h"
#include "Server.h"
#include "View.h"

int main() {
	Server server{ "../test/server.json" };
	std::cout << "Server created" << std::endl;

	std::vector<Info> infos = server.readAll();
	std::cout << "Read all infos" << std::endl;

	SummaryView view{ infos };
	view.display();

	CreateView view2{ infos };
	view2.display();
	std::cout << std::endl;
	view2.confirmCreate();

	return 0;
}