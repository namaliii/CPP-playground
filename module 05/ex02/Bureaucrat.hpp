/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:29 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/25 15:26:42 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <exception>

#include "AForm.hpp"

#define GREEN(text) "\033[38;5;28m" text "\033[0m"
#define BLUE(text) "\033[38;5;32m" text "\033[0m"

class AForm;

class Bureaucrat {
	private:
		const	std::string name;
		int 	grade;
		void	validateGrade(int grade) const;
	public:

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override {
					return "Cannot increase Bureaucrat's grade!";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override {
					return "Cannot decrease Bureaucrat's grade!";
				}
		};

		Bureaucrat() = default;
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& form) const;
		void executeForm(const AForm& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif