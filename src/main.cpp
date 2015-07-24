#include <iostream>
#include <controld/ListenSocket.hpp>
#include <controld/Command.hpp>

int main(int, char **) {
	controld::ListenSocket listenSock(controld::Address::Any, controld::Port(1337));
	while(listenSock) {
		auto clientSock = listenSock.Accept();
		controld::Command cmd;
		clientSock >> cmd;
		std::cout << "received cmd: " << cmd << std::endl;
	}
	return 0;
}
