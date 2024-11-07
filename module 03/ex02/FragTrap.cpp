/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:33:08 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/07 19:04:29 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "NONAME Frag";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
		std::cout << "FragTrap " << name << " constructor called" << std::endl;
		this->hitPoints = 100;
		this->energyPoints = 100;
		this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}


void FragTrap::attack(const std::string& target) {
	if (this->hitPoints == 0 || this->energyPoints == 0) {
		std::cout << "FragTrap " << this->name
			<< " cannot attack because it has no energy or hit points left!"
				<< std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " attacks "
		<< target << ", causing " << this->attackDamage
			<< " points of damage!" << std::endl;
	this->energyPoints--;
}

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
