/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:28:26 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 22:05:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "AAnimal.hpp"

Brain::Brain() {
	std::cout << SOFT_GREEN("Brain default constructor called") << std::endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << SOFT_GREEN("Brain copy constructor called") << std::endl;
	*this = copy;
}

Brain::~Brain() {
	std::cout << YELLOW("Brain default destructor called") << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	std::cout << BLUE("Brain copy assignment operator called") << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

void Brain::newIdea(const std::string& idea) {
	for (int i = 0; i < 100; i++) {
		if (ideas[i].empty()) {
			std::cout << BLUE("Brain is adding a new idea...") << std::endl;
			ideas[i] = idea;
			return;
		}
	}
	std::cout << BOLD(RED("The Brain is full!")) << std::endl;
}

void Brain::printIdeas() const {
	for (int i = 0; i < 100; i++) {
		if (this->ideas[i].empty() == false) {
			std::cout << BOLD(CYAN("Idea ")) << i + 1 << ": " << this->ideas[i] << std::endl;
		}
	}
}
