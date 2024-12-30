#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <stdexcept>

#define RED(text) "\033[38;5;160m" << text << "\033[0m"
#define GREEN(text) "\033[38;5;28m" << text << "\033[0m"

class RPN {
	private:
		std::stack<int> stack;

		bool isOperator(const std::string &token);
		int performOperation(const std::string &op, int a, int b);
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int calculate(const std::string &expression);
};

#endif