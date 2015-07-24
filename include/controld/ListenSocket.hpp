#pragma once

#include <controld/Address.hpp>
#include <controld/Port.hpp>
#include <controld/ClientSocket.hpp>

namespace controld {
	class ListenSocket {
	public:
		ListenSocket(const Address addr, const Port port) {}

		explicit inline operator bool() { return false; }

		inline ClientSocket Accept() {
			throw "not implemented";
		}
	};
}
