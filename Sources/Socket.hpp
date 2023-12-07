#pragma once

#include "Common/ws2.hpp"
#include "Common/ESNetError.hpp"
#include "StaticArray.hpp"
#include "DynamicArray.hpp"
#include <span>
#include <tuple>
#include <string_view>

namespace ESNet {
	class Socket {
	public:
		Socket();
		Socket(u32 const octets, u16 const port, u64 const socket);
		Socket(Socket&& socket) noexcept;

		ESNetError bind(std::string_view const& address, u16 const port);
		ESNetError connect(std::string_view const& address, u16 const port);
		ESNetError listen();
		std::tuple<Socket, ESNetError> accept();
		ESNetError close();

		template <u64 size> ESNetError send(stl::StaticArray<u08, size> const& data) const {
			i32 result = -1;

			result = ::send(m_Socket, reinterpret_cast<const char*>(std::data(data)), static_cast<i32>(std::size(data)), NULL);
			if (result == SOCKET_ERROR) {
				auto const& enum_entry = getEnumEntry(static_cast<ESNetError>(::WSAGetLastError()));
				return enum_entry.error;
			}

			return ESNetError::Success;
		}
		template <u64 size> std::tuple<stl::StaticArray<u08, size>, ESNetError> receive() const {
			i32 result = -1;
			
			stl::StaticArray<u08, size> buffer;

			result = ::recv(m_Socket, reinterpret_cast<char*>(std::data(buffer)), static_cast<i32>(std::size(buffer)), NULL);
			if (result == SOCKET_ERROR) {
				auto const& enum_entry = getEnumEntry(static_cast<ESNetError>(::WSAGetLastError()));
				return { buffer, enum_entry.error };
			}

			return { buffer, ESNetError::Success };
		}

		u32 octets() const;
		u16 port() const;

	private:
		u32 m_Octets;
		u16 m_Port;
		u64 m_Socket;
	};
}