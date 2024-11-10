/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:57:36 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 22:25:50 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal() {
	std::cout << GREEN("WrongAAnimal class default constructor called") << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal &copy) : type(copy.type) {
	std::cout << GREEN("WrongAAnimal class copy constructor called") << std::endl;
	*this = copy;
}

WrongAAnimal::~WrongAAnimal() {
		std::cout << RED("WrongAAnimal class default destructor called") << std::endl;
}

WrongAAnimal& WrongAAnimal::operator=(const WrongAAnimal& rhs) {
	std::cout << BLUE("WrongAAnimal class copy assignment operator called") << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

std::string WrongAAnimal::getType() const {
	return type;
}

