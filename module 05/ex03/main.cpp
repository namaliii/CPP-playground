/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/28 19:26:04 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
	Intern intern;
	Bureaucrat leo("Leo", 50);

	try {
		AForm* shrubbery = intern.makeForm("shrubbery creation", "Home");
		if (shrubbery) {
			shrubbery->beSigned(leo);
			shrubbery->execute(leo);
		}
		delete shrubbery;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		AForm* robotomy = intern.makeForm("robotomy request", "Bender");
		if (robotomy) {
			robotomy->beSigned(leo);
			robotomy->execute(leo);
		}
		delete robotomy;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		AForm* pardon = intern.makeForm("presidential pardon", "Alice");
		if (pardon) {
			pardon->beSigned(leo);
			pardon->execute(leo);
		}
		delete pardon;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		AForm* invalid = intern.makeForm("invalid form", "Nowhere");
		if (invalid) {
			invalid->beSigned(leo);
			invalid->execute(leo);
		}
		delete invalid;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
