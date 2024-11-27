/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:14:27 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/27 22:52:45 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		const		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

		void execute(const Bureaucrat& executor) const override;
		const std::string& getTarget() const;
};

#endif