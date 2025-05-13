Webserv Project Overview

The Webserv project is about building a simple HTTP server in C++98. You'll need to:

    Parse HTTP requests.

    Serve static and dynamic content.

    Handle HTTP methods like GET, POST, etc.

    Respond with appropriate status codes (e.g., 200 OK, 404 Not Found).

    Use socket programming to communicate over the network.

	Step 1: Understanding the HTTP Protocol

HTTP (Hypertext Transfer Protocol) is the foundation of data communication on the web. Here's a simple breakdown of HTTP messages:

    Request: Sent by the client (browser) to the server.

        Format: METHOD /path HTTP/1.1

        Example: GET /index.html HTTP/1.1

    Response: Sent by the server back to the client.

        Format: HTTP/1.1 200 OK

        Example: HTTP/1.1 200 OK

Each response includes headers (e.g., Content-Type) and a body (e.g., HTML content).
Step 2: Create a Simple Socket Server

To begin, you need to create a simple TCP server using sockets in C++. This allows you to listen for incoming HTTP requests.
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the address
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << PORT << "...\n";

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Read request from client (browser)
    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);
    std::cout << "Request:\n" << buffer << std::endl;

    // Send a simple HTTP response
    const char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
    send(new_socket, response, strlen(response), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}

