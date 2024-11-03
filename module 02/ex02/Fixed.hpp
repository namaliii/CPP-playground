/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:37:50 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/03 19:22:26 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const& copy);
		~Fixed();

		Fixed& operator=(const Fixed& rhs);

		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		Fixed operator++(int); // post
		Fixed operator--(int); // post

		Fixed& operator++(void); // pre
		Fixed& operator--(void); // pre

		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		static Fixed& min(Fixed& num1, Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);

		static const Fixed& min(const Fixed& num1, const Fixed& num2);
		static const Fixed& max(const Fixed& num1, const Fixed& num2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed& fixed);

# endif