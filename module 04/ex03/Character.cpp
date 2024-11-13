/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:10:54 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/13 15:41:57 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "Floor.hpp"

Character::Character() : name("NONAME") {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = nullptr;
	}
}

Character::Character(const std::string& name) {
	this->name = name;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = nullptr;
	}
}

Character::Character(const Character& src) {
	this->name = src.name;
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i] != nullptr) {
			this->inventory[i] = src.inventory[i]->clone();
		} else {
			this->inventory[i] = nullptr;
		}
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != nullptr)
			delete this->inventory[i];
	}
}

Character& Character::operator=(const Character& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i] != nullptr)
				delete this->inventory[i];
			if (rhs.inventory[i] != nullptr) {
				this->inventory[i] = rhs.inventory[i]->clone();
			} else {
				this->inventory[i] = nullptr;
			}
		}
	}
	return *this;
}

const std::string& Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (m == nullptr) return;
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == nullptr) {
			inventory[i] = m;
			std::cout << "Materia " << m->getType() << " has been equipped" << std::endl;
			return;
		}
	}
	std::cout << m->getType() << "'s inventory is full!" << std::endl;
	delete m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && inventory[idx] != nullptr) {
		if (!inventoryFloor.addMateria(inventory[idx])) {
			std::cout << "Floor is full! Could not unequip." << std::endl;
		} else {
			std::cout << "Materia " << inventory[idx]->getType() << " has been unequipped" << std::endl;
			inventory[idx] = nullptr;
		}
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || !inventory[idx]) {
		std::cout << "idx " << idx << " is out of range or given slot is empty" << std::endl;
		return;
	}
	inventory[idx]->use(target);
}
