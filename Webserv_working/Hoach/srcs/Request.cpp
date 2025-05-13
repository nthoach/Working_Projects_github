#include "Request.hpp"
#include <sstream>
#include <iostream>

Request::Request() {}

void Request::parse(const std::string& raw_request)
{
    std::istringstream stream(raw_request);
    std::string line;
    bool foundEmptyLine = false;
    std::ostringstream bodyStream;

    // First line: Method Path HTTP version
    if (std::getline(stream, line)) {
        std::istringstream line_stream(line);
        line_stream >> method >> path >> http_version;
    }

    // Skip headers
    while (std::getline(stream, line))
	{
        if (line == "\r" || line.empty())
		{
            foundEmptyLine = true;
            break;
        }
    }

    // Read body if available
    if (foundEmptyLine)
	{
        while (std::getline(stream, line))
		{
            bodyStream << line << '\n';
        }
        body = bodyStream.str();
    }
}
