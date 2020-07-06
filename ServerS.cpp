#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#include <winsock2.h>
#include <vector>
#pragma warning(disable:4996)


int main(int argc, char* argv[])
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	
	std::vector<std::string> secQueue;
	std::vector<std::string> queue = { "1", "2", "3" };
	while (queue.size() > 0) {
		
			newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
			if (newConnection == 0)
				std::cout << "Error #2\n";
			else
				std::cout << "Client Connected:\n";

				char msg[64] = "Communication configured!";
				std::vector<std::string> secQueue;
				queue.pop_back();
				send(newConnection, msg, sizeof(msg), NULL);
				
	}
	system("pause");
	return 0;
}
