/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:09 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/13 21:25:33 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:
		Brain *wrongCatBrain;
	public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();

	WrongCat& operator=(const WrongCat& rhs);

	void makeSound() const;
	void addIdea(const std::string& idea) const;
	Brain& getBrain() const;
};

#endif