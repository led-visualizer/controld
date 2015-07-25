#pragma once

#include <unistd.h>
#include <netdb.h>
//#include <sys/types.h>
//#include <sys/socket.h>
#include <stdexcept>
#include <controld/Address.hpp>
#include <controld/Port.hpp>
#include <controld/ClientSocket.hpp>

namespace controld {
	class ListenSocket {
	private:
		int fd;
		bool listening = false;
	public:
		ListenSocket(const Address address, const Port port) {
			struct sockaddr_in addr = {};
			addr.sin_family = AF_INET;
			addr.sin_addr.s_addr = htonl(INADDR_ANY);
			addr.sin_port = htons(port.number);

			fd = socket(AF_INET, SOCK_STREAM, 0);
			if(fd == -1) {
				throw std::runtime_error("failed to open socket");
			}

			if(bind(fd, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr))) {
				throw std::runtime_error("failed to bind socket");
			}

			if(listen(fd, 10) == -1) {
				throw std::runtime_error("failed to listen on socket");
			}

			listening = true;
		}

		~ListenSocket() {
			if(close(fd) == -1) {
				throw std::runtime_error("failed to close socket");
			}
		}

		explicit inline operator bool() { return listening; }

		inline ClientSocket Accept() {
			int clientFd = accept(fd, NULL, NULL);
			if(clientFd == -1) {
				throw std::runtime_error("failed to accept client connection");
			}
			return ClientSocket(clientFd);
		}
	};
}
