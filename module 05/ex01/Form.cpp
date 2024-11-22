/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:24:30 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/22 19:51:48 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("NONAME"), signedStatus(false), signGrade(150), execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: name(name), signedStatus(false), signGrade(signGrade), execGrade(execGrade) {
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
}

Form::Form(const Form& src) : name(src.name), signedStatus(src.signedStatus),
	signGrade(src.signGrade), execGrade(src.execGrade) {}

Form::~Form() {}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		signedStatus = rhs.signedStatus;
	}
	return *this;
}

const std::string& Form::getName() const {
	return name;
}

bool Form::isSigned() const {
	return signedStatus;
}

int Form::getSignGrade() const {
	return signGrade;
}

int Form::getExecGrade() const {
	return execGrade;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= signGrade)
		signedStatus = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form Name: " << form.getName() << "\n"
	<< "Signed: " << (form.isSigned() ? "Yes" : "No") << "\n"
	<< "Grade required to sign: " << form.getSignGrade() << "\n"
	<< "Grade required to execute: " << form.getExecGrade();
	return os;
}

