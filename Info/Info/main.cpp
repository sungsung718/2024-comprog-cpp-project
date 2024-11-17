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
	std::cout << std::endl;

	CreateView view2{ infos };
	view2.display();
	std::cout << std::endl;
	view2.confirmCreate();
	std::cout << std::endl;

	Info info = server.readItem(1);
	DetailView view3{ info };
	view3.display();

	return 0;
}