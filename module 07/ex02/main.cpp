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

#include "Array.hpp"

int main() {
	try {
		std::cout << GREEN("\nTesting default constructor:") << std::endl;
		Array<int> arr1;
		std::cout << YELLOW("Size of arr1: ") << arr1.size() << std::endl;

		std::cout << GREEN("\nTesting parameterized constructor:") << std::endl;
		Array<int> arr2(5);
		std::cout << YELLOW("Size of arr2: ") << arr2.size() << std::endl;

		std::cout << GREEN("\nTesting array access operator:") << std::endl;
		for (size_t i = 0; i < arr2.size(); ++i) {
			arr2[i] = i * 2;
		}
		std::cout << BLUE("arr2 elements: ");
		for (size_t i = 0; i < arr2.size(); ++i) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;

		std::cout << GREEN("\nTesting copy constructor:") << std::endl;
		Array<int> arr3(arr2);
		std::cout << BLUE("arr3 elements (copied from arr2): ");
		for (size_t i = 0; i < arr3.size(); ++i) {
			std::cout << arr3[i] << " ";
		}
		std::cout << std::endl;

		std::cout << GREEN("\nTesting assignment operator:") << std::endl;
		Array<int> arr4 = arr2;
		std::cout << BLUE("arr4 elements (assigned from arr2): ");
		for (size_t i = 0; i < arr4.size(); ++i) {
			std::cout << arr4[i] << " ";
		}
		std::cout << std::endl;

		std::cout << GREEN("\nTesting constant array access:") << std::endl;
		const Array<int> arr5(5);
		std::cout << BLUE("arr5 elements (read-only): ");
		for (size_t i = 0; i < arr5.size(); ++i) {
			std::cout << arr5[i] << " ";
		}
		std::cout << std::endl;
		std::cout << GREEN("\nTesting out of bounds exception:") << std::endl;
		try {
			std::cout << arr2[10] << std::endl;
		} catch (const std::exception& e) {
			std::cout << RED("Exception caught: ") << e.what() << std::endl;
		}

	} catch (const std::exception& e) {
		std::cout << "An exception occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
