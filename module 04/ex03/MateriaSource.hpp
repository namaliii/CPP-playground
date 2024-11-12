/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:30:44 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/12 19:45:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource {
	private:
		AMateria* materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& rhs);
		void learnMateria(AMateria*) override;
		AMateria* createMateria(const std::string& type) override;
};

#endif