#include "Response.hpp"
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include "utils.hpp"

void Response::send(int socket)
{
    std::string response = "HTTP/1.1 " + status + "\r\n";
    response += "Content-Type: " + content_type + "\r\n";
    response += "Content-Length: "  + int_to_string(body.length()) + "\r\n";
    response += "\r\n";
    response += body;

    ::send(socket, response.c_str(), response.size(), 0);
}

std::string get_mime_type(const std::string& path)
{
    if (path.find(".html") != std::string::npos) return "text/html";
    if (path.find(".css") != std::string::npos) return "text/css";
    if (path.find(".js") != std::string::npos) return "application/javascript";
    if (path.find(".jpg") != std::string::npos || path.find(".jpeg") != std::string::npos) return "image/jpeg";
    if (path.find(".png") != std::string::npos) return "image/png";
    if (path.find(".txt") != std::string::npos) return "text/plain";
    return "application/octet-stream";
}
