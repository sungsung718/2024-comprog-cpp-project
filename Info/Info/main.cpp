#include <iostream>
#include "Info.h"
#include "Server.h"
#include "View.h"

int main() {
	Server server{ "../test/server.json" };
	std::cout << "Server created" << std::endl;

	return 0;
}