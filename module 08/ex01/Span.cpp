/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:02:27 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/13 23:31:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), container() {}

Span::Span(unsigned int N) : _N(N), container() {}

Span::Span(const Span &src) : _N(src._N), container(src.container) {}

Span::~Span() {}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs) {
		_N = rhs._N;
		container = rhs.container;
	}
	return (*this);
}

void Span::addNumber(int number) {
	if (container.size() >= _N)
		throw std::out_of_range(RED("The Span is full, cannot add more numbers!"));
	container.push_back(number);
}

int Span::shortestSpan() const {
	if (container.size() < 2)
		throw std::logic_error(RED("Not enough numbers to calculate span"));
	std::vector<int> sorted = container;
	std::sort(sorted.begin(), sorted.end());
	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++) {
		shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
	}
	return shortest;
}

int Span::longestSpan() const {
	if (container.size() < 2)
		throw std::logic_error(RED("Not enough numbers to calculate span"));
	int longest = *std::max_element(container.begin(), container.end())
		- *std::min_element(container.begin(), container.end());
	return longest;
}

void Span::printContainer() const {
	std::cout << GREEN("Container is of size ") << container.size() << GREEN(" and contains: ");
	for (int num : this->container)
		std::cout << num << " ";
	std::cout << std::endl;
}