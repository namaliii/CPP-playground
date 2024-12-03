/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:48:12 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/03 13:41:39 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src), target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const {
	return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	verifyExecution(executor);

	std::ofstream outfile(target + "_shrubbery");
	if (outfile.is_open()) {
		std::cout << target << " shrubbery has been planted successfully!" << std::endl;
		outfile << "    c    \n";
		outfile << "   c c    \n";
		outfile << "  cccccc  \n";
		outfile << " cccccccc \n";
		outfile << "    ||    \n";
		outfile.close();
	} else {
		throw std::ios_base::failure("Failed to create file.");
	}
}
