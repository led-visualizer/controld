#include <iostream>
#include <controld/ListenSocket.hpp>
#include <controld/Message.hpp>

int main(int, char **) {
	controld::ListenSocket listenSock(controld::Address::Any, controld::Port(1337));
	while(listenSock) {
		auto clientSock = listenSock.Accept();
		controld::Message message;
		clientSock >> message;
		std::cout << message << std::endl;
		switch(message.command) {
			case controld::Command::SetRed:
				std::cerr << "TODO: set red LED intensity" << std::endl;
				break;
			case controld::Command::SetGreen:
				std::cerr << "TODO: set green LED intensity" << std::endl;
				break;
			case controld::Command::SetBlue:
				std::cerr << "TODO: set blue LED intensity" << std::endl;
				break;
			case controld::Command::SetAll:
				std::cerr << "TODO: set all LED intensities" << std::endl;
				break;
			default:
				break;
		}
	}
	return 0;
}
