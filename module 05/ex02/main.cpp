/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/25 16:03:20 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	srand(time(0));

	Bureaucrat anna("Anna", 1);
	Bureaucrat leo("Leo", 50);
	Bureaucrat navid("Navid", 138);

	std::cout << BLUE("\nAvailable forms:\n*********\n");
	ShrubberyCreationForm shrubbery("home");
	std::cout << BLUE("*********") << std::endl;

	std::cout << GREEN("\nTest 1:\n") << std::endl;
	try {
		std::cout << anna << std::endl;
		anna.signForm(shrubbery);
		anna.executeForm(shrubbery);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE("\nAvailable forms:\n*********\n");
	RobotomyCreationForm robotomy("robot");
	std::cout << BLUE("*********") << std::endl;

	std::cout << GREEN("\nTest 2:\n") << std::endl;
	try {
		std::cout << leo << std::endl;
		leo.signForm(robotomy);
		leo.executeForm(robotomy);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE("\nAvailable forms:\n*********\n");
	PresidentialPardonForm pardon("Alice");
	std::cout << BLUE("*********") << std::endl;

	std::cout << GREEN("\nTest 3:\n") << std::endl;
	try {
		std::cout << anna << std::endl;
		anna.signForm(pardon);
		anna.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BLUE("\nAvailable forms:\n*********\n");
	ShrubberyCreationForm shrubbery1("park");
	RobotomyCreationForm robotomy1("R2D2");
	std::cout << BLUE("*********") << std::endl;

	std::cout << GREEN("\nTest 4:\n") << std::endl;
	try {
		std::cout << navid << std::endl;
		navid.signForm(shrubbery1);
		navid.executeForm(shrubbery1);
		navid.signForm(robotomy1);
		navid.executeForm(robotomy1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		leo.executeForm(shrubbery1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
