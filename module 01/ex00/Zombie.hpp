/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:18:22 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/24 18:08:47 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie(std::string name);
		~Zombie();

	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
