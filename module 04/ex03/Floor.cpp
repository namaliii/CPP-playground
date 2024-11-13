/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:08:31 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/13 15:15:54 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() {
	for (int i = 0; i < FLOOR_MAX; ++i) {
		content[i] = nullptr;
	}
}

Floor::Floor(const Floor& src) {
	for (int i = 0; i < FLOOR_MAX; ++i) {
		if (src.content[i]) {
			content[i] = src.content[i]->clone();
		} else {
			content[i] = nullptr;
		}
	}
}

Floor::~Floor() {
	for (int i = 0; i < FLOOR_MAX; ++i) {
		delete content[i];
		content[i] = nullptr;
	}
}

Floor& Floor::operator=(const Floor& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < FLOOR_MAX; ++i) {
			delete content[i];
			content[i] = nullptr;
		}

		for (int i = 0; i < FLOOR_MAX; ++i) {
			if (rhs.content[i]) {
				content[i] = rhs.content[i]->clone();
			} else {
				content[i] = nullptr;
			}
		}
	}
	return *this;
}

bool Floor::addMateria(AMateria* materia) {
	for (int i = 0; i < FLOOR_MAX; ++i) {
		if (content[i] == nullptr) {
			content[i] = materia;
			return true;
		}
	}
	std::cout << "Error! the floor is full!" << std::endl;
	return false;
}