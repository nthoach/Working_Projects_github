#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>

class Response
{
public:
    std::string status;
    std::string content_type;
    std::string body;

    void send(int socket);

};

std::string get_mime_type(const std::string& path);

#endif
