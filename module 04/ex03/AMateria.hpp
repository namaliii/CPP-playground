/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:03:26 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/12 22:07:31 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& src);
		virtual ~AMateria();

		AMateria& operator=(const AMateria& rhs);
		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif