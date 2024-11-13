/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:56:29 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/13 15:32:59 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <iostream>
#include "AMateria.hpp"

#define FLOOR_MAX 15

class Floor {
	public:
		AMateria* content[FLOOR_MAX];
		Floor();
		Floor(const Floor& src);
		~Floor();
		Floor& operator=(const Floor& rhs);

		bool addMateria(AMateria* materia);
};

#endif