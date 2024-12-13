/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:40:41 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/13 18:55:54 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stdexcept>

#define GREEN(text) "\033[38;5;28m" text "\033[0m"
#define BLUE(text) "\033[38;5;32m" text "\033[0m"
#define YELLOW(text) "\033[38;5;220m" text "\033[0m"
#define RED(text) "\033[38;5;160m" text "\033[0m"

template <typename T>
void easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(),
		container.end(), value);

	if (it == container.end())
		throw std::out_of_range("Value not found in the container");
	std::cout << GREEN("Value found at index: ") << std::distance(container.begin(), it) << std::endl;
}

template <typename T>
void printContainer(const T& container)
{
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

#endif