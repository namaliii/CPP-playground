/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:31:02 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/07 17:25:09 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoints == 0 || this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name
			<< " cannot attack because it has no energy or hit points left!"
				<< std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks "
		<< target << ", causing " << this->attackDamage
			<< " points of damage!" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name\
			<< " has no hit points left and cannot take more damage!"
				<< std::endl;
		return;
	}
	this->hitPoints = (amount >= this->hitPoints) ? 0 : this->hitPoints - amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount
		<< " points of damage, remaining hit points: "
			<< this->hitPoints << std::endl;
	this->energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints == 0 || this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " cannot repair itself "
			<< "due to lack of energy or hit points!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " repairs iself and gets "
		<< amount << " points back" << std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}
