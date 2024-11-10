/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:30:01 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 21:57:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"
#include "Colors.hpp"

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		AAnimal& operator=(const AAnimal& rhs);

		virtual void makeSound() const = 0;

		std::string getType() const;
};

#endif
