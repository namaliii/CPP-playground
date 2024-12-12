/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:39:22 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/12 20:05:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

#define GREEN(text) "\033[38;5;28m" text "\033[0m"
#define BLUE(text) "\033[38;5;32m" text "\033[0m"
#define YELLOW(text) "\033[38;5;220m" text "\033[0m"
#define RED(text) "\033[38;5;160m" text "\033[0m"

template <typename T>
class Array {
	private:
		T* _array;
		size_t _size;
	public:
		Array();
		Array(size_t n);
		Array(const Array& other);
		~Array();
		Array& operator=(const Array& other);
		T& operator[](size_t index);
        const T& operator[](size_t index) const;
		size_t size() const;
};

#include "Array.tpp"

#endif