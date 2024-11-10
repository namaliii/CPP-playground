/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:39:36 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/09 14:00:03 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog class default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog class copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog() {
		std::cout << "Dog class default destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << "Dog class copy assignment operator called" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!";
}
