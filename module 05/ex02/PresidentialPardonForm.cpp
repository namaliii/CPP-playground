/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:19:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/25 15:27:31 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src), target(src.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const \
	PresidentialPardonForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	verifyExecution(executor);

	std::cout << target
	<< " has been pardoned by our noble and gracious Zaphon Beeblebrox!" << std::endl;
}
