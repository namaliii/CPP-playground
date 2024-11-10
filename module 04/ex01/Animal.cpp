/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:32:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 20:45:48 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << GREEN("Animal class default constructor called") << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type) {
	std::cout << GREEN("Animal class copy constructor called") << std::endl;
	*this = copy;
}

Animal::~Animal() {
		std::cout << RED("Animal class default destructor called") << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
	std::cout << BLUE("Animal class copy assignment operator called") << std::endl;
		if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << ITALIC(BLUE("Animal sound"));
}
