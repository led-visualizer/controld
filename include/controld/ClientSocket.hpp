#pragma once

#include <cstdint>
#include <stdexcept>
#include <netdb.h>
#include <endian.hpp>

namespace controld {
	class ClientSocket {
	private:
		const int fd;
	public:
		ClientSocket(const int fd) : fd(fd) {}

		~ClientSocket() {
			if(close(fd) == -1) {
				throw std::runtime_error("failed to close client connection");
			}
		}

		inline char Read() {
			char c;
			ssize_t bytesRead = read(fd, &c, 1);
			if(bytesRead == -1) {
				throw std::runtime_error("failed to read byte");
			}
			return c;
		}

		inline void Read(char *buffer, const std::size_t numBytes) {
			for(std::size_t i = 0; i < numBytes; ++i) {
				buffer[i] = Read();
			}
		}

		inline std::string Read(const std::size_t numBytes) {
			std::string str;
			str.resize(numBytes);
			ssize_t bytesRead = read(fd, reinterpret_cast<void *>(&str[0]), numBytes);
			if(bytesRead == -1) {
				throw std::runtime_error("failed to read bytes");
			}
			if(bytesRead != static_cast<ssize_t>(numBytes)) { str.resize(bytesRead); }
			return str;
		}
	};

	inline ClientSocket & operator >>(ClientSocket &clientSock, std::uint8_t &i) {
		i = clientSock.Read();
		return clientSock;
	}

	inline ClientSocket & operator >>(ClientSocket &clientSock, std::uint16_t &i) {
		std::uint16_t n;
		clientSock.Read(reinterpret_cast<char *>(&n), 2);
		i = swapbe(n);
		return clientSock;
	}
}
