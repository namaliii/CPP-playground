/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:06 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/19 15:49:53 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << RED("Usage: ") << RED(argv[0]) << RED(" <input_file>") << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.loadData("data.csv");
	btc.processInputFile(argv[1]);

	return 0;
}