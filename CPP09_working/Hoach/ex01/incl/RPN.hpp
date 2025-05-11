#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<int> _stack;

        bool isOperator(char c) const;
        void applyOperator(char op);

    public:
        RPN();
        ~RPN();

        int evaluate(const std::string& expression);
};

#endif
