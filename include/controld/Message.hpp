#pragma once

#include <cstdint>
#include <iostream>
#include <controld/ClientSocket.hpp>

namespace controld {
	enum class Command : std::uint8_t {
		None,
		Something
	};

	inline std::ostream & operator <<(std::ostream &os, const Command command) {
		switch(command) {
			case Command::None:
				os << "None";
				break;
			case Command::Something:
				os << "Something";
				break;
			default:
				os << "Invalid";
				break;
		}
		return os;
	}

	class Message {
	public:
		Command command;

		Message(Command command = Command::None) : command(command) {}
	};

	inline std::ostream & operator <<(std::ostream &os, const Message &message) {
		os << message.command;
		return os;
	}

	inline ClientSocket & operator >>(ClientSocket &clientSock, Message &message) {
		message.command = static_cast<Command>(clientSock.Read());
		return clientSock;
	}
}
