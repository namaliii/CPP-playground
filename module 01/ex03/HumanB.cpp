/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:14:42 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/25 18:01:32 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::attack() const {
	if (this->weapon)
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}