#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int right = _stack.top(); _stack.pop();
    int left = _stack.top(); _stack.pop();
    int result = 0;

    if (op == '+')
        result = left + right;
    else if (op == '-')
        result = left - right;
    else if (op == '*')
        result = left * right;
    else if (op == '/') {
        if (right == 0)
            throw std::runtime_error("Error");
        result = left / right;
    }

    _stack.push(result);
}

int RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) // read whitespace-delimited word to token from iss
    {
        if (token.length() == 1 && isOperator(token[0]))
        {
            applyOperator(token[0]);
        }
        else if (token.length() == 1 && std::isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
