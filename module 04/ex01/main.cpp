/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:02:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 22:09:31 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void) {
	std::cout << BOLD("\nPolymorphism: Just checkin\'\n") << std::endl;
	const Animal* meta = new Animal();
	const Animal* Fafik = new Dog();
	const WrongAnimal* WrongGarfield = new WrongCat();
	std::cout << std::endl;
	std::cout << "Object meta " << meta->getType() << "has no type yet and does \"";
	meta->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << "Object Fafik is a " << Fafik->getType() << " and does \"";
	Fafik->makeSound();
	std::cout << "\"" << std::endl;
	std::cout << "Object WrongGarfield is a " << WrongGarfield->getType() << " and does \"";
	WrongGarfield->makeSound();
	std::cout << "\"\n" << std::endl;
	delete meta;
	delete Fafik;
	delete WrongGarfield;
	std::cout << "***************************" << std::endl;
	std::cout << BOLD("\nArray of animal objects, half of which are dogs, half are cats\n") << std::endl;
	const Animal* animals[8];
	for (int i = 0; i < 4; i++) {
		animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 4; i < 8; i++) {
		animals[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0; i < 8; i++) {
		delete animals[i];
	}
	std::cout << "***************************" << std::endl;

	std::cout << BOLD("\nAdding some ideas to the Brains!\n") << std::endl;
	const Cat* Garfield = new Cat();
	const Cat* Klakier = new Cat();
	const Dog* Azor = new Dog();
	std::cout << std::endl;
	Garfield->addIdea("I'm kinda sleepy");
	Garfield->addIdea("Maybe a little nap before dinner...");
	Garfield->addIdea("Lasagna sounds like a good idea.");
	Garfield->addIdea("I wonder if there's lasagna left in the fridge.");
	Garfield->addIdea("What if I eat lasagna in bed?");
	Klakier->addIdea("It's time for us cats to take over the world.");
	Klakier->addIdea("Step one: bend humans to our will.");
	Klakier->addIdea("I should start a meeting with other cats about world domination.");
	Klakier->addIdea("How should the cats rule the world with lazy asses like this guy here...");
	Azor->addIdea("Walk and snack?");
	Azor->addIdea("Bark, walk, snack!");
	Azor->addIdea("Chase tail... snack?");
	Azor->addIdea("Snack first, then walk.");
	Azor->addIdea("Did I smell something?");
	std::cout << ITALIC(MAGENTA("\nWhat does Cat Garfield think of? Let's see...")) << std::endl;
	Garfield->getBrain().printIdeas();
	std::cout << std::endl;
	std::cout << ITALIC(MAGENTA("And how about Cat Klakier?")) << std::endl;
	Klakier->getBrain().printIdeas();
	std::cout << std::endl;
	std::cout << ITALIC(MAGENTA("Let's check what does Dog Azor think of...")) << std::endl;
	Azor->getBrain().printIdeas();
	std::cout << std::endl;
	delete Klakier;
	delete Garfield;
	delete Azor;
	std::cout << "***************************" << std::endl;
	return 0;
}