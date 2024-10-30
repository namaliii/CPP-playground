/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:36:12 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/30 21:55:32 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(Fixed const& copy);
		Fixed& operator = (Fixed const& rhs);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

# endif