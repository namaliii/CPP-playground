/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:57:36 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 20:44:20 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << GREEN("WrongAnimal class default constructor called") << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type) {
	std::cout << GREEN("WrongAnimal class copy constructor called") << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal() {
		std::cout << RED("WrongAnimal class default destructor called") << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	std::cout << BLUE("WrongAnimal class copy assignment operator called") << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << ITALIC(BLUE("WrongAnimal sound"));
}
