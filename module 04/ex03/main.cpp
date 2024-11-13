/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:03:01 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/13 22:39:27 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("Ali");

	std::cout << BOLD_UNDERLINE("\n*Capacity of MateriaSource (up to 4 Materias)*\n") << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << BOLD_UNDERLINE("\n*Trying to use Materia with correct & incorrect index*\n") << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(14, *bob);

	std::cout << BOLD_UNDERLINE("\n*Unequipping Materia*\n") << std::endl;
	me->unequip(1);
	me->unequip(0);
	me->unequip(100);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}