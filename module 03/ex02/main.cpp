/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:30:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/07 19:15:18 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	FragTrap Poke1("Pikachu");
	FragTrap Poke2("Bulbasaur");
	ScavTrap Poke3("Jigglypuff");

	std::cout << std::endl;
	Poke1.attack("Bulbasaur");
	Poke2.takeDamage(13);
	Poke2.takeDamage(15);
	Poke2.takeDamage(10);
	Poke2.beRepaired(20);

	Poke2.attack("Pikachu");
	Poke1.takeDamage(30);
	Poke1.takeDamage(50);
	Poke1.takeDamage(30);
	Poke1.beRepaired(30);
	Poke2.highFiveGuys();

	Poke2.attack("Jigglypuff");
	Poke3.takeDamage(60);
	Poke3.beRepaired(30);
	Poke3.attack("Bulbasaur");
	Poke3.guardGate();
	std::cout << std::endl;
	return 0;
}