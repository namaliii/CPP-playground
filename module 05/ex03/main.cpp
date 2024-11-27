/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/27 22:47:26 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	srand(time(0));
	ShrubberyCreationForm shrubbery1("park");
	std::cout << BLUE("\nAvailable forms:\n*********\n");
	std::cout << shrubbery1 << std::endl;
	std::cout << BLUE("*********") << std::endl;

	std::cout << GREEN("\nTest 1:\n") << std::endl;
	Bureaucrat leo("Leo", 50);
	Bureaucrat navid("Navid", 138);
	try {
		std::cout << navid << std::endl;
		navid.signForm(shrubbery1);
		navid.executeForm(shrubbery1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << leo << std::endl;
		leo.executeForm(shrubbery1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	RobotomyCreationForm robotomy("robot");
	std::cout << BLUE("\nAvailable forms:\n*********\n");
	std::cout << robotomy << std::endl;
	std::cout << BLUE("*********") << std::endl;

	std::cout << GREEN("\nTest 2:\n") << std::endl;
	try {
		std::cout << leo << std::endl;
		leo.signForm(robotomy);
		leo.executeForm(robotomy);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	PresidentialPardonForm pardon("Alice");
	std::cout << BLUE("\nAvailable forms:\n*********\n");
	std::cout << pardon << std::endl;
	std::cout << BLUE("*********") << std::endl;

	std::cout << GREEN("\nTest 3:\n") << std::endl;
	Bureaucrat anna("Anna", 5);
	try {
		std::cout << anna << std::endl;
		anna.signForm(pardon);
		anna.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
