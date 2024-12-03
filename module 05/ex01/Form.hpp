/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:24:23 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:29 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool 				signedStatus;
		const int			signGrade;
		const int			execGrade;
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

		Form();
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& src);
		~Form();
		Form& operator=(const Form& rhs);

		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif