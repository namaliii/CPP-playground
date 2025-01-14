/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:39:36 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/21 15:19:56 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << LIGHT_GREEN("Dog class default constructor called") << std::endl;
	type = "Dog";
	this->dogBrain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal(copy) {
	std::cout << LIGHT_GREEN("Dog class copy constructor called") << std::endl;
	dogBrain = new Brain(*copy.dogBrain);
}

Dog::~Dog() {
	delete this->dogBrain;
	std::cout << LIGHT_RED("Dog class default destructor called") << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
std::cout << LIGHT_BLUE("Dog class copy assignment operator called") << std::endl;
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		delete dogBrain;
		dogBrain = new Brain(*rhs.dogBrain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << ITALIC(LIGHT_BLUE("Woof woof!"));
}

void Dog::addIdea(const std::string& idea) const {
	this->dogBrain->newIdea(idea);
}

Brain& Dog::getBrain() const {
	return *dogBrain;
}
