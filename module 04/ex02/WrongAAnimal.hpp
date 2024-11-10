/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:58:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 22:26:01 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAANIMAL_HPP
#define WRONGAANIMAL_HPP

#include <iostream>
#include "Brain.hpp"
#include "Colors.hpp"

class WrongAAnimal {
	protected:
		std::string type;
	public:
		WrongAAnimal();
		WrongAAnimal(const WrongAAnimal &copy);
		virtual ~WrongAAnimal();

		WrongAAnimal& operator=(const WrongAAnimal& rhs);

		virtual void makeSound() const = 0;

		std::string getType() const;
};

#endif
