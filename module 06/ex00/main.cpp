/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:17:26 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/09 21:56:47 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << RED("Wrong number of args!") << GREEN("\nUsage: ./convert <literal>") << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
