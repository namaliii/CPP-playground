/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/21 15:10:12 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat class default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat class copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat() {
		std::cout << "Cat class default destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat class copy assignment operator called" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meooow...";
}
