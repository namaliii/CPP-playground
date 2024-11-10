/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:02:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 22:33:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void) {
	// const AAnimal* abstract = new AAnimal();
	const AAnimal* Fafik = new Dog();
	const WrongAAnimal* WrongGarfield = new WrongCat();
	std::cout << std::endl;
	std::cout << "Object Fafik is a " << Fafik->getType() << " and does \"";
	Fafik->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << "Object WrongGarfield is a " << WrongGarfield->getType() << " and does \"";
	WrongGarfield->makeSound();
	std::cout << "\"\n" << std::endl;
	delete Fafik;
	delete WrongGarfield;
	return 0;
}
