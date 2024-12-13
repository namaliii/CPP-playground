/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:02:38 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/13 23:33:13 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	std::cout << YELLOW("\n* TEST 1 *\n") << std::endl;
	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printContainer();

		std::cout << BLUE("Shortest span: ") << sp.shortestSpan() << std::endl;
		std::cout << MAGENTA("Longest span: ") << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << YELLOW("\n* TEST 2 *\n") << std::endl;
	try {
		std::list<int> lst = {1, 2, 3, 4, 5};
		Span spRange(10);
		spRange.addRange(lst.begin(), lst.end());
		spRange.addNumber(20);
		spRange.printContainer();

		std::cout << BLUE("Shortest span: ") << spRange.shortestSpan() << std::endl;
		std::cout << MAGENTA("Longest span: ") << spRange.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << RED("Exception caught: ") << e.what() << std::endl;
	}
	std::cout << YELLOW("\n* TEST 3 *\n") << std::endl;
	try {
		Span sp(1);
		sp.addNumber(42);
		sp.printContainer();

		std::cout << BLUE("Shortest span: ") << sp.shortestSpan() << std::endl;
		std::cout << MAGENTA("Longest span: ") << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED("\nException caught! ") << e.what() << std::endl;
	}
	std::cout << YELLOW("\n* TEST 4 *\n") << std::endl;
	try {
		Span sp(2);
		sp.addNumber(42);
		sp.addNumber(4);
		sp.addNumber(2);
	} catch (const std::exception& e) {
		std::cerr << RED("Exception caught! ") << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}