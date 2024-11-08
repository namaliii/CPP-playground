/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:29:44 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/08 16:21:32 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), \
		ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &rhs) {
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am, I am, I am " << name << " or maybe... " << ClapTrap::name << std::endl;
}