/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/21 15:19:59 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << DARK_GREEN("WrongCat class default constructor called") << std::endl;
	type = "WrongCat";
	this->wrongCatBrain = new Brain();
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAAnimal(copy) {
	std::cout << DARK_GREEN("WrongCat class copy constructor called") << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	delete this->wrongCatBrain;
	std::cout << DARK_RED("WrongCat class default destructor called") << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	std::cout << DARK_BLUE("WrongCat class copy assignment operator called") << std::endl;
	if (this != &rhs) {
		WrongAAnimal::operator=(rhs);
		*wrongCatBrain = *(rhs.wrongCatBrain);
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << ITALIC(DARK_BLUE("Muuu roar woof how the heck did it go"));
}

void WrongCat::addIdea(const std::string& idea) const {
	this->wrongCatBrain->newIdea(idea);
}

Brain& WrongCat::getBrain() const {
	return *wrongCatBrain;
}
