/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:03:01 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/12 22:35:09 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void le() {
	system("leaks AMateria");
}

// int main(void) {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// } // konrad
// int main()
// {
// 		// suppressClog();
// 	IMateriaSource* src = new MateriaSource();

// 	std::clog << std::endl;
// 	src->learnMateria(new Ice());
// 	std::clog << std::endl;

// 	src->learnMateria(new Cure());
// 	std::clog << std::endl;

// 	src->learnMateria(new Ice());
// 	std::clog << std::endl;

// 	src->learnMateria(new Cure());
// 	std::clog << std::endl;

// 	src->learnMateria(new Cure());
// 	std::clog << std::endl;

// 	ICharacter* me = new Character("me");
// 	std::clog << std::endl;

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	std::clog << std::endl;

// 	me->equip(tmp);
// 	std::clog << std::endl;

// 	tmp = src->createMateria("cure");
// 	std::clog << std::endl;

// 	me->equip(tmp);

// 	tmp = src->createMateria("cure");
// 	std::clog << std::endl;

// 	me->equip(tmp);

// 	tmp = src->createMateria("cure");
// 	std::clog << std::endl;

// 	me->equip(tmp);
// 	std::clog << std::endl;

// 	ICharacter* bob = new Character("bob");
// 	std::clog << std::endl;

// 	me->use(0, *bob);
// 	std::clog << std::endl;

// 	me->use(1, *bob);
// 	std::clog << std::endl;

// 	me->use(1, *bob);
// 	std::clog << std::endl;

// 	me->use(5, *bob);
// 	std::clog << std::endl;

// 	me->use(2, *me);
// 	std::clog << std::endl;


// 	me->unequip(3);

// 	delete tmp;

// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

int main() {
atexit(le);
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("MK");

	std::cout << BOLD_UNDERLINE("\nTEST 1: MateriaSource Capacity up to 4 \n") << std::endl;
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

	std::cout << BOLD_UNDERLINE("\nTEST 2: Wrong Index of Materia to use \n") << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(42, *bob);

	std::cout << BOLD_UNDERLINE("\nTEST 3: Unequip Materia \n") << std::endl;
	// delete me->inventory[1]
	me->unequip(1);
	me->unequip(0);
	me->unequip(100);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}