#define _CRT_SECURE_NO_WARNINGS

#include "ws2.hpp"
#include <array>
#include <string>
#include <cstring>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

namespace ESNet {
	void startup() {
		i32 result = -1;
		::WSAData wsa_data;
		result = ::WSAStartup(MAKEWORD(2, 2), &wsa_data);
		if (result != NULL) {
			std::cout << "WSAStartup failed: " << result << '\n';
			return;
		}
	}
	void shutdown() {
		i32 result = -1;
		result = ::WSACleanup();
		if (result != NULL) {
			std::cout << "WSACleanup failed: " << result << '\n';
			return;
		}
	}

	std::unique_ptr<char[]> processWS2Address(i32 const family, void*const ws2address) {
		static std::array<char, 46> buffer;
		return std::unique_ptr<char[]>(std::strcpy(new char[std::strlen(::inet_ntop(family, ws2address, std::data(buffer), std::size(buffer))) + 1], std::data(buffer)));
	}

	::addrinfo* getaddrinfo(std::string_view const& address, u16 const port) {
		i32 result = -1;

		::addrinfo static constexpr address_hints{
			.ai_flags{},
			.ai_family = AF_INET,
			.ai_socktype = SOCK_STREAM,
			.ai_protocol = ::IPPROTO_TCP,
			.ai_addrlen{},
			.ai_canonname{},
			.ai_addr{},
			.ai_next{},
		};
		::addrinfo* address_info;
		std::string port_string = std::to_string(port);

		result = ::getaddrinfo(std::data(address), std::data(port_string), &address_hints, &address_info);
		if (result != NULL) {
			std::cout << "Failed to fetch address info (" << address << ':' << port << "): " << result << '\n';
			return nullptr;
		}

		return address_info;
	}
}