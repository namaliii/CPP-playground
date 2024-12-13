/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:40:54 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/13 18:58:24 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec = {3, 2, 9, 60, 11};
	std::cout << YELLOW("\nVector contents: ");
	printContainer(vec);
	try {
		std::cout << BLUE("\nSearching for number 9 in the vector") << std::endl;
		::easyfind(vec, 9);
	}
	catch (const std::exception& e) {
		std::cout << RED("Exception caught: ") << e.what() << std::endl;
	}
	std::list<int> lst = {44, 1, 12, 42, 70};
	std::cout << YELLOW("\n\nList contents: ");
	printContainer(lst);
	try {
		std::cout << BLUE("\nSearching for number 42 in the list") << std::endl;
		::easyfind(lst, 42);
	}
	catch (const std::exception& e) {
		std::cout << RED("Exception caught: ") << e.what() << std::endl;
	}
	try {
		std::cout << BLUE("\nSearching for number 99 in the list") << std::endl;
		::easyfind(lst, 99);
	}
	catch (const std::exception& e) {
		std::cout << RED("Exception caught: ") << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
