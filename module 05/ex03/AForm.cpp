/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:24:30 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/03 13:39:09 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm()
	: name("NONAME"), signedStatus(false),
	signGrade(150), execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: name(name), signedStatus(false),
	signGrade(signGrade), execGrade(execGrade) {
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
	: name(src.name), signedStatus(src.signedStatus),
	signGrade(src.signGrade), execGrade(src.execGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs) {
		signedStatus = rhs.signedStatus;
	}
	return *this;
}

void AForm::verifyExecution(const Bureaucrat& executor) const {
	if (!isSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > execGrade) {
		throw GradeTooLowException();
	}
}

const std::string& AForm::getName() const {
	if (name.empty()) {
        throw std::runtime_error("Form is invalid!");
    }
	return name;
}

bool AForm::isSigned() const {
	return signedStatus;
}

int AForm::getSignGrade() const {
	return signGrade;
}

int AForm::getExecGrade() const {
	return execGrade;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= signGrade) {
		signedStatus = true;
		std::cout << "Form " << name << " has been signed by " << b.getName() << "." << std::endl;
	} else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	try {
		os << "Form Name: " << form.getName() << "\n"
		<< "Signed: " << (form.isSigned() ? "Yes" : "No") << "\n"
		<< "Grade required to sign: " << form.getSignGrade() << "\n"
		<< "Grade required to execute: " << form.getExecGrade() << "\n"
		<< "Target: " << form.getTarget();
	} catch (const std::exception& e) {
		 os << "Error: " << e.what() << std::endl;
        return os;
	}
	return os;
}

