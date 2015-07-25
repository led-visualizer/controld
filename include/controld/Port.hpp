#pragma once

#include <cstdint>

namespace controld {
	class Port {
	public:
		const std::uint16_t number;
		Port(const std::uint16_t number) : number(number) {}
	};
}
