/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:20:13 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/10 21:51:39 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
	try {
		// Testing default constructor
		Array<int> arr1;
		std::cout << "Size of arr1: " << arr1.size() << std::endl;

		// Testing parameterized constructor
		Array<int> arr2(5);
		std::cout << "Size of arr2: " << arr2.size() << std::endl;

		// Testing subscript operator
		for (unsigned int i = 0; i < arr2.size(); ++i) {
			arr2[i] = i * 2;
		}
		std::cout << "arr2 elements: ";
		for (unsigned int i = 0; i < arr2.size(); ++i) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;

		// Testing copy constructor
		Array<int> arr3(arr2);
		std::cout << "arr3 elements (copied from arr2): ";
		for (unsigned int i = 0; i < arr3.size(); ++i) {
			std::cout << arr3[i] << " ";
		}
		std::cout << std::endl;

		// Testing assignment operator
		Array<int> arr4 = arr2;
		std::cout << "arr4 elements (assigned from arr2): ";
		for (unsigned int i = 0; i < arr4.size(); ++i) {
			std::cout << arr4[i] << " ";
		}
		std::cout << std::endl;

		// Testing out of bounds exception
		try {
			std::cout << arr2[10] << std::endl;  // Will throw exception
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

	} catch (const std::exception& e) {
		std::cout << "An exception occurred: " << e.what() << std::endl;
	}

	return 0;
}
