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
		switch(message.command) {
			case controld::Command::SetRed:
				clientSock << "set red LED intensity to " << std::to_string(message.intensity[0]) << '\n';
				std::cerr << "TODO: set red LED intensity" << std::endl;
				break;
			case controld::Command::SetGreen:
				clientSock << "set green LED intensity to " << std::to_string(message.intensity[1]) << '\n';
				std::cerr << "TODO: set green LED intensity" << std::endl;
				break;
			case controld::Command::SetBlue:
				clientSock << "set blue LED intensity to " << std::to_string(message.intensity[2]) << '\n';
				std::cerr << "TODO: set blue LED intensity" << std::endl;
				break;
			case controld::Command::SetAll:
				clientSock << "set red LED intensity to " << std::to_string(message.intensity[0]) << '\n';
				clientSock << "set green LED intensity to " << std::to_string(message.intensity[1]) << '\n';
				clientSock << "set blue LED intensity to " << std::to_string(message.intensity[2]) << '\n';
				std::cerr << "TODO: set all LED intensities" << std::endl;
				break;
			default:
				break;
		}
	}
	return 0;
}
