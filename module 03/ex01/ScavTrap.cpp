/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:16:35 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/07 17:27:09 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
        std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	    this->hitPoints = 100;
        this->energyPoints = 50;
        this->attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hitPoints == 0 || this->energyPoints == 0) {
		std::cout << "ScavTrap " << this->name
			<< " cannot attack because it has no energy or hit points left!"
				<< std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks "
		<< target << ", causing " << this->attackDamage
			<< " points of damage!" << std::endl;
	this->energyPoints--;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
