/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:39:43 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 21:57:35 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain *dogBrain;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();

		Dog& operator=(const Dog& rhs);

		void makeSound() const override;
		void addIdea(const std::string& idea) const;
		Brain& getBrain() const;
};

#endif