/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:23:27 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/11 22:41:43 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& src) : AMateria(src) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return *this;
}

Ice* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl;
}
