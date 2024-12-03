/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:24:23 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/03 13:21:40 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <ostream>
#include <fstream>
#include <exception>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		void 		verifyExecution(const Bureaucrat& executor) const;
	private:
		const		std::string name;
		bool 		signedStatus;
		const int	signGrade;
		const int	execGrade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override {
					return "this form's grade is too high!";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override {
					return "bureaucrat's grade is too low to sign this form.";
				}
		};
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const noexcept override {
					return "The form is not signed and cannot be executed!";
				}
		};

		AForm();
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& src);
		virtual ~AForm();
		AForm& operator=(const AForm& rhs);

		const std::string& getName() const;
		virtual const std::string& getTarget() const = 0;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& b);

		virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif