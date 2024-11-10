/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:09 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/09 13:09:43 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat& operator=(const Cat& rhs);

	void makeSound() const override;
};

# endif