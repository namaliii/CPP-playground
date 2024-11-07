/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:30:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/07 16:13:11 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap Poke1("Pikachu");
	ClapTrap Poke2("Bulbasaur");

	Poke1.attack("Bulbasaur");
	Poke2.takeDamage(1);
	Poke2.takeDamage(3);
	Poke2.takeDamage(2);
	Poke2.beRepaired(6);

	Poke2.attack("Pikachu");
	Poke1.takeDamage(3);
	Poke1.takeDamage(5);
	Poke1.takeDamage(3);
	Poke1.beRepaired(10);

	return 0;
}