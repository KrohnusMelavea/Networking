#define _CRT_SECURE_NO_WARNINGS

#include "ws2.hpp"
#include <array>
#include <string>
#include <cstring>

#pragma comment(lib, "Ws2_32.lib")

namespace ESNet {
	bool startup() {
		::WSAData wsa_data;
		return ::WSAStartup(MAKEWORD(2, 2), &wsa_data) != SOCKET_ERROR;

	}
	void shutdown() {
		::WSACleanup();
	}

	std::unique_ptr<char[]> processWS2Address(i32 const family, void*const ws2address) {
		static std::array<char, 46> buffer;
		return std::unique_ptr<char[]>(std::strcpy(new char[std::strlen(::inet_ntop(family, ws2address, std::data(buffer), std::size(buffer))) + 1], std::data(buffer)));
	}

	std::tuple<::addrinfo*, ESNetError> getaddrinfo(std::string_view const& address, u16 const port) {
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
		if (result == SOCKET_ERROR) {
			auto const& enum_entry = getEnumEntry(static_cast<ESNetError>(WSAGetLastError()));
			return { nullptr, enum_entry.error };
		}

		return { address_info, ESNetError::Success };
	}
}