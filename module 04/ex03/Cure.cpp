/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:23:27 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/11 22:41:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& src) : AMateria(src) {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return *this;
}

Cure* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl;
}
