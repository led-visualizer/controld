#pragma once

#include <iostream>
#include <controld/ClientSocket.hpp>

namespace controld {
	class Command {

	};

	inline std::ostream & operator <<(std::ostream &os, const Command &cmd) {
		return os;
	}

	inline ClientSocket & operator >>(ClientSocket &clientSock, Command &cmd) {
		return clientSock;
	}
}
