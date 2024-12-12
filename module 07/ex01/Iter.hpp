/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:20:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/12 22:07:48 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <vector>

#define GREEN(text) "\033[38;5;28m" text "\033[0m"
#define BLUE(text) "\033[38;5;32m" text "\033[0m"
#define YELLOW(text) "\033[38;5;220m" text "\033[0m"

template <typename T, typename ft>
void iter(T* array, size_t length, ft func) {
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif