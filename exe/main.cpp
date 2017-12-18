#include "CivetServer.h"
#include <cstring>

#include <windows.h>
#include <chrono>
#include <thread>
#include <iostream>

#include "handlers/AccountHandler.h"

#define DOCUMENT_ROOT "."
#define PORT "8081"
#define EXAMPLE_URI "/example"
#define EXIT_URI "/exit"
bool exitNow = false;

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
	std::vector<std::string> cpp_options = { "document_root", DOCUMENT_ROOT, "listening_ports", "8081r,8443s", "ssl_certificate", "D:\\Programming\\salus\\salus-rest\\resources\\cert\\server.pem" };

	CivetServer server(cpp_options);

	AccountHandler hAccount;
	server.addHandler("/api/account", hAccount);

	while (!exitNow)
	{
		std::this_thread::sleep_for(1s);
	}

	std::cout << "Bye!" << std::endl;;

	return 0;
}