/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:10:46 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/25 15:27:47 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyCreationForm.hpp"

RobotomyCreationForm::RobotomyCreationForm()
	: AForm("RobotomyCreationForm", 72, 45), target("") {}

RobotomyCreationForm::RobotomyCreationForm(const std::string& target)
	: AForm("RobotomyCreationForm", 72, 45), target(target) {}

RobotomyCreationForm::RobotomyCreationForm(const RobotomyCreationForm& src)
	: AForm(src), target(src.target) {}

RobotomyCreationForm::~RobotomyCreationForm() {}

RobotomyCreationForm& RobotomyCreationForm::operator=(const RobotomyCreationForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}

void RobotomyCreationForm::execute(const Bureaucrat& executor) const {
	verifyExecution(executor);

	std::cout << "Buzzzzz buzZz *** drilling noises ****" << std::endl;
	if (rand() % 2) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy of " << target << " has failed!" << std::endl;
	}
}
