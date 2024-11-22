/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/22 20:26:41 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	std::cout << GREEN("\nBureaucrat 1:\n") << std::endl;
	try {
		Bureaucrat b1("Anna", 1);
		std::cout << b1 << std::endl;
		std::cout << BLUE("*********") << std::endl;
		Form f1("Form1", 2, 50);
		std::cout << f1 << std::endl;
		std::cout << BLUE("*********") << std::endl;
		b1.signForm(f1);
		std::cout << BLUE("*********") << std::endl;
		std::cout << f1 << std::endl;
		// std::cout << BLUE("*********") << std::endl;
		// b1.incrementGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << GREEN("\nBureaucrat 2:\n") << std::endl;
	try {
		Bureaucrat b2("Leo", 149);
		std::cout << b2 << std::endl;
		std::cout << BLUE("*********") << std::endl;
		Form f2("Form2", 50, 100);
		std::cout << f2 << std::endl;
		std::cout << BLUE("*********") << std::endl;
		b2.signForm(f2);
		// std::cout << BLUE("*********") << std::endl;
		// b2.incrementGrade();
		// std::cout << b2 << std::endl;
		// b2.decrementGrade();
		// std::cout << b2 << std::endl;
		// b2.decrementGrade();
		// std::cout << b2 << std::endl;
		// b2.decrementGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
