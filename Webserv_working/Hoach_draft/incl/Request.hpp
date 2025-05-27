#pragma once

#include <string>

class Request
{
public:
    std::string method;
    std::string path;
    std::string http_version;
    std::string body; // <-- Add this line

    Request();
    void parse(const std::string& raw_request);
};

