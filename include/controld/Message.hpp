#pragma once

#include <cstdint>
#include <iostream>
#include <controld/ClientSocket.hpp>

namespace controld {
	class Message {
	public:
		std::uint16_t red;
		std::uint16_t green;
		std::uint16_t blue;
	};

	inline std::ostream & operator <<(std::ostream &os, const Message &message) {
		return os << "Message " << message.red << ' ' << message.green << ' ' << message.blue;
	}

	inline ClientSocket & operator >>(ClientSocket &clientSock, Message &message) {
		return clientSock >> message.red >> message.green >> message.blue;
	}
}
