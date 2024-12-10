/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:50:50 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/10 21:51:05 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < _size; ++i) {
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other) {
		return *this;
	}

	T* new_array = new T[other._size];
	for (unsigned int i = 0; i < other._size; ++i) {
		new_array[i] = other._array[i];
	}

	delete[] _array;

	_array = new_array;
	_size = other._size;
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::exception();
	}
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size) {
		throw std::exception();
	}
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

#endif
