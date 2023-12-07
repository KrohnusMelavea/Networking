#include "Common/ws2.hpp"
#include "Socket.hpp"
#include <memory>
#include <thread>
#include <iostream>

namespace ESNet {
	Socket::Socket() : m_Octets{ 0 }, m_Port{ 0 }, m_Socket{ INVALID_SOCKET } {
		m_Socket = ::socket(AF_INET, SOCK_STREAM, ::IPPROTO_TCP);
	}
	Socket::Socket(u32 const octets, u16 const port, u64 const socket) : m_Octets{ octets }, m_Port{ port }, m_Socket{ socket } {

	}
	Socket::Socket(Socket&& socket) noexcept : m_Octets{ socket.m_Octets }, m_Port{ socket.m_Port }, m_Socket{ socket.m_Socket } {
		socket.m_Octets = NULL;
		socket.m_Port = NULL;
		socket.m_Socket = INVALID_SOCKET;
	}

	ESNetError Socket::bind(std::string_view const& address, u16 const port) {
		i32 result = -1;

		auto [address_info, address_info_status] = getaddrinfo(address, port);
		if (address_info_status != ESNetError::Success) {
			return address_info_status;
		}

		result = ::bind(m_Socket, address_info->ai_addr, static_cast<i32>(address_info->ai_addrlen));
		if (result == SOCKET_ERROR) {
			::freeaddrinfo(address_info);
			auto const& enum_entry = getEnumEntry(static_cast<ESNetError>(::WSAGetLastError()));
			return enum_entry.error;
		}

		::freeaddrinfo(address_info);

		m_Octets = addressToOctets(address);
		m_Port = port;

		return ESNetError::Success;
	}
	ESNetError Socket::connect(std::string_view const& address, u16 const port) {
		i32 result = -1;
		
		auto [address_info, address_info_status] = getaddrinfo(address, port);
		if (address_info_status != ESNetError::Success) {
			return address_info_status;
		}

		result = ::connect(m_Socket, address_info->ai_addr, static_cast<i32>(address_info->ai_addrlen));
		if (result == SOCKET_ERROR) {
			::freeaddrinfo(address_info);
			auto const& enum_entry = getEnumEntry(static_cast<ESNetError>(::WSAGetLastError()));
			return enum_entry.error;
		}

		::freeaddrinfo(address_info);

		m_Octets = addressToOctets(address);
		m_Port = port;

		return ESNetError::Success;
	}
	ESNetError Socket::listen() {
		i32 result = -1;

		result = ::listen(m_Socket, SOMAXCONN);
		if (result == SOCKET_ERROR) {
			auto const& enum_entry = getEnumEntry(static_cast<ESNetError>(::WSAGetLastError()));
			return enum_entry.error;
		}

		return ESNetError::Success;
	}
	std::tuple<Socket, ESNetError> Socket::accept() {
		u64 socket_handle = INVALID_SOCKET;
		::sockaddr_in address{};
		i32 address_length = sizeof(::sockaddr_in);
		socket_handle = ::accept(m_Socket, reinterpret_cast<::sockaddr*>(&address), &address_length);
		auto const addr = processWS2Address(AF_INET, &address.sin_addr);
		std::cout << addr.get() << '\n';
		if (socket_handle == INVALID_SOCKET) {
			auto const& enum_entry = getEnumEntry(static_cast<ESNetError>(::WSAGetLastError()));
			return { Socket{}, enum_entry.error };
		}
		return { Socket{addressToOctets(std::string_view{addr.get(), static_cast<std::size_t>(std::strlen(addr.get()))}), m_Port, socket_handle}, ESNetError::Success };
	}

	ESNetError Socket::close() {
		i32 result = -1;

		result = ::closesocket(m_Socket);
		if (result == SOCKET_ERROR) {
			auto const& enum_entry = getEnumEntry(static_cast<ESNetError>(::WSAGetLastError()));
			return enum_entry.error;
		}

		m_Socket = INVALID_SOCKET;
		return ESNetError::Success;
	}

	u32 Socket::octets() const { return m_Octets; }
	u16 Socket::port() const { return m_Port; }
}