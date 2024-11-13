/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:39:43 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/13 21:25:43 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
	private:
		Brain *wrongDogBrain;
	public:
	WrongDog();
	WrongDog(const WrongDog &copy);
	~WrongDog();

	WrongDog& operator=(const WrongDog& rhs);

	void makeSound() const;
	void addIdea(const std::string& idea) const;
	Brain& getBrain() const;
};

# endif