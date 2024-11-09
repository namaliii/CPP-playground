/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:32:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/09 13:59:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal class default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type) {
	std::cout << "Animal class copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal() {
		std::cout << "Animal class default destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
	std::cout << "Animal class copy assignment operator called" << std::endl;
		if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound";
}
