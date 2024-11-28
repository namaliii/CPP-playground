/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:04:28 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/28 18:11:48 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class AForm;

class Intern {
	public:
		class InvalidFormException : public std::exception {
			public:
				const char* what() const noexcept override {
					return "invalid form name!";
				}
		};

		Intern();
		Intern(const Intern& src);
		virtual ~Intern();
		Intern& operator=(const Intern& rhs);

		AForm* makeForm(const std::string& formName,
			const std::string& formTarget);
};

#endif