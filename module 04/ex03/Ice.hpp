/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:23:30 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/12 20:06:09 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& src);
		~Ice();

		Ice& operator=(const Ice& rhs);
		Ice* clone() const override;
		void use(ICharacter& target) override;
};

#endif