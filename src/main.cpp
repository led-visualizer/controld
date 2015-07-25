#include <iostream>
#include <controld/ListenSocket.hpp>
#include <controld/Message.hpp>

int main(int, char **) {
	controld::ListenSocket listenSock(controld::Address::Any, controld::Port(1337));
	while(listenSock) {
		auto clientSock = listenSock.Accept();
		controld::Message message;
		clientSock >> message;
		std::cout << "received message: " << message << std::endl;
	}
	return 0;
}
