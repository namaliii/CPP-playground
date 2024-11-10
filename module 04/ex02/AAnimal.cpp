/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:35:19 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 22:35:23 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << GREEN("AAnimal class default constructor called") << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.type) {
	std::cout << GREEN("AAnimal class copy constructor called") << std::endl;
	*this = copy;
}

AAnimal::~AAnimal() {
		std::cout << RED("AAnimal class default destructor called") << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	std::cout << BLUE("AAnimal class copy assignment operator called") << std::endl;
		if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

std::string AAnimal::getType() const {
	return type;
}
