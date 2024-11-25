/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:32 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/25 14:30:43 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name), grade(grade) {
	validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: name(src.name), grade(src.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs) {
		grade = rhs.grade;
	}
	return *this;
}

void Bureaucrat::validateGrade(int grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	grade--;
	validateGrade(grade);
}

void Bureaucrat::decrementGrade() {
	grade++;
	validateGrade(grade);
}

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName() << " because "
			<< e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << "." << std::endl;
	} catch (std::exception& e) {
		std::cerr<< name << " couldn't execute "
			<< form.getName() << ": " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
