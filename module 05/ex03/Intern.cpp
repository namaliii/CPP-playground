/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:28:20 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/28 18:14:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
	*this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return *this;
}

typedef AForm* (*FormCreator)(const std::string&);

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

std::string toLower(const std::string& str) {
	std::string lowerStr = str;
	for (size_t i = 0; i < str.length(); i++) {
		lowerStr[i] = std::tolower(str[i]);
	}
	return lowerStr;
}


AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	std::string lowerFormName = toLower(formName);

	const std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	FormCreator creators[] = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (size_t i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](formTarget);
		}
	}
	throw InvalidFormException();
}
