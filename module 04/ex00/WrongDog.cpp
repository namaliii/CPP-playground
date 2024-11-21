/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:39:36 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/21 15:17:21 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog() {
	std::cout << "WrongDog class default constructor called" << std::endl;
	type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog &copy) : WrongAnimal(copy) {
	std::cout << "WrongDog class copy constructor called" << std::endl;
	*this = copy;
}

WrongDog::~WrongDog() {
		std::cout << "WrongDog class default destructor called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& rhs) {
	std::cout << "WrongDog class copy assignment operator called" << std::endl;
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

void WrongDog::makeSound() const {
	std::cout << "Meow or roar not sure";
}
