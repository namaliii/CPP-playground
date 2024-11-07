/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:30:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/07 19:09:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
	FragTrap Poke1("Pikachu");
	FragTrap Poke2("Bulbasaur");

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
	std::cout << std::endl;
	return 0;
}