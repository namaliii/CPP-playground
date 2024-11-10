/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:02:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/09 13:59:14 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

void le() {
	system("leaks Animal");
}

int main(void) {
	// atexit(le);
	const Animal* meta = new Animal();
	const Animal* Fafik = new Dog();
	const Animal* Garfield = new Cat();
	std::cout << std::endl;
	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* WrongFafik = new WrongDog();
	const WrongAnimal* WrongGarfield = new WrongCat();
	std::cout << std::endl;
	std::cout << "Object Fafik is a " << Fafik->getType() << " and does \"";
	Fafik->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << "Object Garfield is a " << Garfield->getType() << " and does \"";
	Garfield->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << "Object meta " << meta->getType() << "has no type yet and does \"";
	meta->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << "Object WrongFafik is a " << WrongFafik->getType() << " and does \"";
	WrongFafik->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << "Object WrongGarfield is a " << WrongGarfield->getType() << " and does \"";
	WrongGarfield->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << "Object WrongMeta " << WrongMeta->getType() << "has no type yet and does \"";
	WrongMeta->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << std::endl;
	delete meta;
	delete Fafik;
	delete Garfield;
	std::cout << std::endl;
	delete WrongMeta;
	delete WrongFafik;
	delete WrongGarfield;
	return 0;
}