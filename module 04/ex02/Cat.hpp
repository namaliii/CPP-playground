/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:09 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 21:57:23 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

#include <iostream>

class Cat : public AAnimal {
	private:
		Brain *catBrain;
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();

		Cat& operator=(const Cat& rhs);

		void makeSound() const override;
		void addIdea(const std::string& idea) const;
		Brain& getBrain() const;
};

#endif
