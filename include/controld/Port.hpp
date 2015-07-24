#pragma once

#include <cstdint>

namespace controld {
	class Port {
	private:
		const std::uint16_t portNumber;
	public:
		Port(const std::uint16_t portNumber) : portNumber(portNumber) {}
	};
}
