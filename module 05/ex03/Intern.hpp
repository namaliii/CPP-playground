/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:04:28 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/27 23:12:33 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const std::string& name, int signGrade, int execGrade);
		Intern(const Intern& src);
		virtual ~Intern();
		Intern& operator=(const Intern& rhs);

		Form makeForm();
};

#endif