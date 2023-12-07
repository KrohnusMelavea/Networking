#include "Sources/Common/ws2.hpp"
#include "Sources/Socket.hpp"
#include <thread>
#include <iostream>

int main() {
	ESNet::startup();	
	ESNet::Socket server, client;
	server.bind("127.0.0.1", 27015);
	server.listen();
	client.connect("127.0.0.1", 27015);
	auto [server_client, accept_status] = server.accept();
	stl::StaticArray<u08, 512> send_data{ 3 };
	server_client.send(send_data);
	auto [receive_data, receive_status] = client.receive<512>();
	std::cout << static_cast<u32>(receive_data[0]) << '\n';
	client.close();
	server_client.close();
	server.close();
	ESNet::shutdown();
}