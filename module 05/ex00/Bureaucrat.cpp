/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:32 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/22 17:16:46 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade) {}

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
