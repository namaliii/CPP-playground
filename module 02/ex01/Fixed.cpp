/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:49:37 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/05 15:19:13 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->value = static_cast<int>(roundf(value * (1 << fractionalBits)));
	// std::cout << "Float value converted to fixed-point: " << this->value << std::endl;
}

Fixed::Fixed(Fixed const& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->value = rhs.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const {
	return value;
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	// std::cout << "converting " << value << " to ";
	// return value >> fractionalBits;
	return (value + (1 << (fractionalBits - 1))) >> fractionalBits;
}

std::ostream& operator<<(std::ostream &os, const Fixed& fixed) {
	os << fixed.toFloat();
	// std::cout << " ...before converting with toFloat it was " << fixed.getRawBits();
	return os;
}
