/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:37:57 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/03 20:55:26 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int value) {
	this->value = value << fractionalBits;
}

Fixed::Fixed(const float value) {
	this->value = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(Fixed const& copy) {
	*this = copy;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator = (Fixed const& rhs) {
	if (this != &rhs) {
		this->value = rhs.getRawBits();
	}
	return (*this);
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++(int) {
	Fixed temp = (*this);
	value++;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp = (*this);
	value--;
	return temp;
}

Fixed& Fixed::operator++(void) {
	value++;
	return (*this);
}

Fixed& Fixed::operator--(void) {
	value--;
	return (*this);
}

bool Fixed::operator>(const Fixed& rhs) const {
	return toFloat() > rhs.toFloat();
}

bool Fixed::operator<(const Fixed& rhs) const {
	return toFloat() < rhs.toFloat();
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return toFloat() <= rhs.toFloat();
}

bool Fixed::operator==(const Fixed& rhs) const {
	return toFloat() == rhs.toFloat();
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return toFloat() != rhs.toFloat();
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
	return (num1 < num2 ? num1 : num2);
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
	return (num1 > num2 ? num1 : num2);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
	return (num1 < num2 ? num1 : num2);
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) {
	return (num1 > num2 ? num1 : num2);
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
	return value >> fractionalBits;

}

std::ostream& operator<<(std::ostream &os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
