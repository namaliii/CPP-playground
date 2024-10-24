/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:19:06 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/24 18:22:00 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *heapZombie;

	heapZombie = newZombie("Joanna");
	heapZombie->announce();
	randomChump("stack Steven");
	delete(heapZombie);
	return(0);
}
