#include <iostream>
#include "Info.h"
#include "Server.h"

int main() {
	Server server{ "../test/server.json" };
	std::cout << "Server created" << std::endl;

	return 0;
}