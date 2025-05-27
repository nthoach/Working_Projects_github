#include "utils.hpp"
#include <fstream>
#include <sstream>

std::string read_file(const std::string& path)
{
    std::ifstream file(path.c_str());
    if (!file.is_open())
        return "<html><body><h1>File not found</h1></body></html>";
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

// Replacement for std::to_string in C++98
std::string int_to_string(int num) {
    std::ostringstream ss;
    ss << num;
    return ss.str();
}
