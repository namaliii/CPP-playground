/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:51:44 by anamieta          #+#    #+#             */
/*   Updated: 2025/01/10 20:56:57 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	stack = other.stack;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		stack = other.stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(const std::string &op, int a, int b) {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0) throw std::logic_error("Division by zero");
		return a / b;
	}
	throw std::invalid_argument("Unknown operator: " + op);
}

int RPN::calculate(const std::string &expression) {
	std::istringstream input(expression);
	std::string token;

	while (input >> token) {
		if (std::isdigit(token[0]) && token.size() == 1) {
			stack.push(token[0] - '0');
		} else if (isOperator(token)) {
			if (stack.size() < 2) throw std::logic_error("Not enough operands");

			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();

			stack.push(performOperation(token, a, b));
		} else {
			throw std::invalid_argument("Invalid token");
		}
	}

	if (stack.size() != 1) throw std::invalid_argument("Too many operands");

	return stack.top();
}
