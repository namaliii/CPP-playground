/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:31:40 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/12 20:06:16 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& src);
		~Cure();

		Cure& operator=(const Cure& rhs);
		Cure* clone() const override;
		void use(ICharacter& target) override;
};

#endif