/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 21:59:46 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << DARK_GREEN("Cat class default constructor called") << std::endl;
	type = "Cat";
	this->catBrain = new Brain();
}

Cat::Cat(const Cat &copy) {
	std::cout << DARK_GREEN("Cat class copy constructor called") << std::endl;
	*this = copy;
}

Cat::~Cat() {
	delete this->catBrain;
	std::cout << DARK_RED("Cat class default destructor called") << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << DARK_BLUE("Cat class copy assignment operator called") << std::endl;
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		*catBrain = *(rhs.catBrain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << ITALIC(DARK_BLUE("Meooow..."));
}

void Cat::addIdea(const std::string& idea) const {
	this->catBrain->newIdea(idea);
}

Brain& Cat::getBrain() const {
	return *catBrain;
}
