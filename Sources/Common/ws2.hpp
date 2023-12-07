#pragma once

#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Common/types.hpp"
#include "ESNetError.hpp"
#include <windows.h>
#include <iphlpapi.h>
#include <tuple>
#include <memory>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string_view>

namespace ESNet {
	bool startup();
	void shutdown();

	std::tuple<::addrinfo*, ESNetError> getaddrinfo(std::string_view const& address, u16 const port);
	std::unique_ptr<char[]> processWS2Address(i32 const family, void *const ws2address);

	inline constexpr u32 addressToOctets(std::string_view const& address) noexcept {
		u32 octets = 0;
		
		u32 octet = 0;
		auto const* const data = std::data(address);
		auto const* const last = data + std::size(address);
		auto* c = data;
		for (u32 i = 0; c <= last; ++c) {
			if (*c == '.' || c == last) {
				octets |= octet << (24 - 8 * i++);
				octet = 0;
				continue;
			}
			octet = (octet * 10) + *c - '0';
		}

		return octets;
	}
	inline constexpr u08 getOctet(u32 const octets, u32 const octet) noexcept {
		return octets >> octet * 8 & 255;
	}
	inline constexpr u08 getOctetLength(u08 const octet) noexcept {
		return (octet > 99) + (octet > 9) + 1;
	}
	inline constexpr std::string octetsToAddress(u32 const octets) noexcept {
		u08 const octet0 = getOctet(octets, 0);
		u08 const octet1 = getOctet(octets, 1);
		u08 const octet2 = getOctet(octets, 2);
		u08 const octet3 = getOctet(octets, 3);
		u08 const octet0length = getOctetLength(octet0);
		u08 const octet1length = getOctetLength(octet1);
		u08 const octet2length = getOctetLength(octet2);
		u08 const octet3length = getOctetLength(octet3);
		std::string address(octet0length + octet1length + octet2length + octet3length + 3, '0');
		char* data = std::data(address);
		if (octet3length > 2) { *data++ = '0' + octet3 / 100; }
		if (octet3length > 1) { *data++ = '0' + (octet3 % 100) / 10; }
		*data++ = '0' + (octet3 % 10);
		*data++ = '.';
		if (octet2length > 2) { *data++ = '0' + octet2 / 100; }
		if (octet2length > 1) { *data++ = '0' + (octet2 % 100) / 10; }
		*data++ = '0' + (octet2 % 10);
		*data++ = '.';
		if (octet1length > 2) { *data++ = '0' + octet1 / 100; }
		if (octet1length > 1) { *data++ = '0' + (octet1 % 100) / 10; }
		*data++ = '0' + (octet1 % 10);
		*data++ = '.';
		if (octet0length > 2) { *data++ = '0' + octet0 / 100; }
		if (octet0length > 1) { *data++ = '0' + (octet0 % 100) / 10; }
		*data++ = '0' + (octet0 % 10);
		return address;
	}
}