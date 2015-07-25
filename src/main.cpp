#include <iostream>
#include <string>
#include <controld/ListenSocket.hpp>
#include <controld/Message.hpp>

int main(int, char **) {
	controld::ListenSocket listenSock(controld::Address::Any, controld::Port(1337));
	while(listenSock) {
		auto clientSock = listenSock.Accept();
		controld::Message message;
		clientSock >> message;
		std::cout << message << std::endl;
		clientSock << "set red LED intensity to " << std::to_string(message.red) << '\n';
		clientSock << "set green LED intensity to " << std::to_string(message.green) << '\n';
		clientSock << "set blue LED intensity to " << std::to_string(message.blue) << '\n';
		std::cerr << "TODO: set LED intensities" << std::endl;
	}
	return 0;
}
