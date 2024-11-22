/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/22 17:18:57 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	std::cout << GREEN("Bureaucrat 1:") << std::endl;
	try {
		Bureaucrat b1("Anna", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << GREEN("\nBureaucrat 2:") << std::endl;
	try {
		Bureaucrat b2("Leo", 149);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << GREEN("\nBureaucrat 3:") << std::endl;
	try {
		Bureaucrat b3("Joe", 151);
		std::cout << b3 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}