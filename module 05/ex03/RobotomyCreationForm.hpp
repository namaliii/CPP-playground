/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:10:14 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/25 14:11:23 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYCREATIONFORM_HPP
#define ROBOTOMYCREATIONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyCreationForm : public AForm {
	private:
		const		std::string target;
	public:
		RobotomyCreationForm();
		RobotomyCreationForm(const std::string& target);
		RobotomyCreationForm(const RobotomyCreationForm& src);
		~RobotomyCreationForm();
		RobotomyCreationForm& operator=(const RobotomyCreationForm& rhs);

		void execute(const Bureaucrat& executor) const override;
};

#endif