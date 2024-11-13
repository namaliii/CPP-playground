/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:10:51 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/13 15:22:40 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Floor.hpp"

class Character : public ICharacter {
	protected:
		std::string name;
		AMateria* inventory[4];
		Floor inventoryFloor;
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& src);
		~Character();
		Character& operator=(const Character& rhs);

		const std::string& getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif