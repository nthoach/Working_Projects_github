#include "Request.hpp"
#include "Response.hpp"
#include "utils.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdio>

#define PORT 8081

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket failed");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return 1;
    }

    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        return 1;
    }

    std::cout << "Server listening on http://localhost:" << PORT << "\n";

    while (true)
	{
        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        char buffer[4096];
        std::memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, 4095);

        Request req;
        req.parse(buffer);
		Response res;
        if (req.method == "GET")
		{
            std::string file_path = "." + req.path;
            std::string body = read_file(file_path);
            if (!body.empty())
			{
                res.status = "200 OK";
                res.content_type = get_mime_type(file_path);
                res.body = body;
            } 
			else
			{
                res.status = "404 Not Found";
                res.content_type = "text/html";
                res.body = "<h1>404 Not Found</h1>";
            }
        } 
		else if (req.method == "POST")
		{
            res.status = "200 OK";
            res.content_type = "text/plain";
            res.body = "Received POST:\n" + req.body;
        }
		else if (req.method == "DELETE")
		{
            std::string file_path = "." + req.path;
            if (remove(file_path.c_str()) == 0)
			{
                res.status = "200 OK";
                res.content_type = "text/plain";
                res.body = "Deleted " + req.path + "\n";
            }
			else
			{
                res.status = "404 Not Found";
                res.content_type = "text/plain";
                res.body = "Cannot delete or file not found.";
            }
        } 
		else
		{
            res.status = "405 Method Not Allowed";
            res.content_type = "text/plain";
            res.body = "Method not allowed.";
        }
        res.send(new_socket);
        close(new_socket);
    }
    close(server_fd);
    return 0;
}
