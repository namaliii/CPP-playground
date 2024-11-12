/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:34:22 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/12 22:21:38 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	for (int i = 0; i < 4; i++) {
		if (src.materias[i] != nullptr) {
			this->materias[i] = src.materias[i]->clone();
		} else {
			this->materias[i] = nullptr;
		}
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] != nullptr)
			delete this->materias[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (this->materias[i] != nullptr)
				delete this->materias[i];
			if (rhs.materias[i] != nullptr) {
				this->materias[i] = rhs.materias[i]->clone();
			} else {
				this->materias[i] = nullptr;
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* newMateria) {
	if (newMateria == nullptr)
		return;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] == nullptr) {
			this->materias[i] = newMateria;
			std::cout << "Materia " << newMateria->getType() << " is now in memory." << std::endl;
			return;
		}
		else if (this->materias[i] == newMateria) {
			std::cout << "Materia " << newMateria->getType() << " is already learned!" << std::endl;
			return;
		}
	}
	delete newMateria;
	std::cout << "No more space left in the memory of MateriaSource!" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] && materias[i]->getType() == type) {
			return materias[i]->clone();
		}
	}
	std::cout << "Materia " << type << " is unknown." << std::endl;
	return nullptr;
}
