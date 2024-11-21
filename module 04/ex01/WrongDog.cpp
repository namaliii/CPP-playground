/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:39:36 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/21 15:17:34 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog() {
	std::cout << LIGHT_GREEN("WrongDog class default constructor called") << std::endl;
	type = "WrongDog";
	this->wrongDogBrain = new Brain();
}

WrongDog::WrongDog(const WrongDog &copy) : WrongAnimal(copy) {
	std::cout << LIGHT_GREEN("WrongDog class copy constructor called") << std::endl;
	*this = copy;
}

WrongDog::~WrongDog() {
	delete this->wrongDogBrain;
	std::cout << LIGHT_RED("WrongDog class default destructor called") << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& rhs) {
	std::cout << LIGHT_BLUE("WrongDog class copy assignment operator called") << std::endl;
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
		*wrongDogBrain = *(rhs.wrongDogBrain);
	}
	return *this;
}

void WrongDog::makeSound() const {
	std::cout << ITALIC(LIGHT_BLUE("Meow or roar not sure"));
}

void WrongDog::addIdea(const std::string& idea) const {
	this->wrongDogBrain->newIdea(idea);
}

Brain& WrongDog::getBrain() const {
	return *wrongDogBrain;
}