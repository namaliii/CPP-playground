/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:06 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/18 22:00:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: wrong number of args" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.loadData("data.csv");
	if (exchange.getDataMap().empty()) {
		std::cerr << "Error: data.csv is empty or invalid." << std::endl;
		return 1;
	}
	exchange.processInputFile(argv[1]);
	return 0;
}
