/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/03 19:48:24 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) {
	Intern intern;
	Bureaucrat leo("Leo", 50);

	std::cout << GREEN("\nTest 1:\n") << std::endl;
	AForm* shrubbery = nullptr;
	try {
		shrubbery = intern.makeForm("shrubbery creation", "Home");
		std::cout << BLUE("*********") << std::endl;
		std::cout << *shrubbery << std::endl;
		std::cout << BLUE("*********") << std::endl;
		shrubbery->beSigned(leo);
		shrubbery->execute(leo);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	delete shrubbery;

	std::cout << GREEN("\nTest 2:\n") << std::endl;
	AForm* robotomy = nullptr;
	try {
		robotomy = intern.makeForm("robotomy request", "Bender");
		std::cout << BLUE("*********") << std::endl;
		std::cout << *robotomy << std::endl;
		std::cout << BLUE("*********") << std::endl;
		robotomy->beSigned(leo);
		robotomy->execute(leo);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	delete robotomy;

	std::cout << GREEN("\nTest 3:\n") << std::endl;
	AForm* pardon = nullptr;
	try {
		pardon = intern.makeForm("presidential pardon", "Alice");
		std::cout << BLUE("*********") << std::endl;
		std::cout << *pardon << std::endl;
		std::cout << BLUE("*********") << std::endl;
		pardon->beSigned(leo);
		pardon->execute(leo);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	delete pardon;

	std::cout << GREEN("\nTest 4:\n") << std::endl;
	AForm* invalid = nullptr;
	try {
		invalid = intern.makeForm("invalid form", "Nowhere");
		std::cout << BLUE("*********") << std::endl;
		std::cout << *invalid << std::endl;
		std::cout << BLUE("*********") << std::endl;
		invalid->beSigned(leo);
		invalid->execute(leo);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	delete invalid;

	return 0;
}
