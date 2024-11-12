/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:03:18 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/12 19:24:26 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string type) : type(type) {}

AMateria::AMateria(const AMateria& src) {
	*this = src;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

const std::string& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria is used on " << target.getName() << std::endl;
}