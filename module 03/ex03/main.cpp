/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:30:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/07 22:49:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	FragTrap 	Poke1("Pikachu");
	ScavTrap 	Poke2("Jigglypuff");
	DiamondTrap Poke3("Bulbasaur");

	std::cout << std::endl;
	Poke1.attack("Bulbasaur");
	Poke2.takeDamage(30);
	Poke2.attack("Trapaichu");
	Poke1.takeDamage(20);
	Poke3.attack("Trapaichu");
	Poke1.takeDamage(100);
	Poke3.attack("Bulbasaur");
	Poke2.takeDamage(100);

	Poke3.whoAmI();

	Poke3.attack("Trapoichusaur");
	Poke3.takeDamage(100);
	std::cout << std::endl;
	return 0;
}