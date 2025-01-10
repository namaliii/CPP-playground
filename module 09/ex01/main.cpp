/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:51:26 by anamieta          #+#    #+#             */
/*   Updated: 2025/01/10 21:03:27 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED("Please insert 2 args:\n\n"
		"./executableName followed by mathematical expression\n"
		"in Reverse Polish Notation, separated by spaces,\n"
		"i.e. \"2 9 + 6 *\"") << std::endl;
		return 1;
	}
	RPN rpn;
	try {
		int result = rpn.calculate(argv[1]);
		std::cout << GREEN("Result: " << result) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED("Error: " << e.what()) << std::endl;
		return 1;
	}
	return 0;
}

