/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:30:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/07 17:26:31 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap Poke1("Pikachu");
	ScavTrap Poke2("Bulbasaur");

	std::cout << std::endl;
	Poke1.attack("Bulbasaur");
	Poke2.attack("Pikachu");
	Poke2.guardGate();
	std::cout << std::endl;
	return 0;
}