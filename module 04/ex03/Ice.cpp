/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:23:27 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/12 19:27:07 by anamieta         ###   ########.fr       */
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
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
}
