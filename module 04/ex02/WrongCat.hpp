/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:09 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 22:25:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAAnimal.hpp"

class WrongCat : public WrongAAnimal {
	private:
		Brain *wrongCatBrain;
	public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();

	WrongCat& operator=(const WrongCat& rhs);

	void makeSound() const override;
	void addIdea(const std::string& idea) const;
	Brain& getBrain() const;
};

#endif
