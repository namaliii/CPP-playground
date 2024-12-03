/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/03 14:53:10 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) {
	Intern intern;
	Bureaucrat leo("Leo", 50);

	std::cout << GREEN("\nTest 1:\n") << std::endl;
	try {
		AForm* shrubbery = intern.makeForm("shrubbery creation", "Home");
		std::cout << BLUE("*********") << std::endl;
		std::cout << *shrubbery << std::endl;
		std::cout << BLUE("*********") << std::endl;
		if (shrubbery) {
			shrubbery->beSigned(leo);
			shrubbery->execute(leo);
		}
		delete shrubbery;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << GREEN("\nTest 2:\n") << std::endl;
	try {
		AForm* robotomy = intern.makeForm("robotomy request", "Bender");
		std::cout << BLUE("*********") << std::endl;
		std::cout << *robotomy << std::endl;
		std::cout << BLUE("*********") << std::endl;
		if (robotomy) {
			robotomy->beSigned(leo);
			robotomy->execute(leo);
		}
		delete robotomy;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << GREEN("\nTest 3:\n") << std::endl;
	try {
		AForm* pardon = intern.makeForm("presidential pardon", "Alice");
		std::cout << BLUE("*********") << std::endl;
		std::cout << *pardon << std::endl;
		std::cout << BLUE("*********") << std::endl;
		if (pardon) {
			pardon->beSigned(leo);
			pardon->execute(leo);
		}
		delete pardon;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << GREEN("\nTest 4:\n") << std::endl;
	try {
		AForm* invalid = intern.makeForm("invalid form", "Nowhere");
		std::cout << BLUE("*********") << std::endl;
		std::cout << *invalid << std::endl;
		std::cout << BLUE("*********") << std::endl;
		if (invalid) {
			invalid->beSigned(leo);
			invalid->execute(leo);
		}
		delete invalid;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
