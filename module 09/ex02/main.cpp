/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:51:58 by anamieta          #+#    #+#             */
/*   Updated: 2025/01/16 20:00:18 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << RED("Please insert numbers that I can sort! :)") << std::endl;
		return 1;
	}
	try {
		PmergeMe sorter(argc, argv);

		sorter.sortAndDisplay();
	} catch (const std::exception& e) {
		std::cerr << RED("Error: " << e.what()) << std::endl;
		return 1;
	}

	return 0;
}
