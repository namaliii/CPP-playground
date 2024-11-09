/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/09 14:00:19 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat class default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat class copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
		std::cout << "WrongCat class default destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	std::cout << "WrongCat class copy assignment operator called" << std::endl;
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Muuu roar woof how the heck did it go";
}
