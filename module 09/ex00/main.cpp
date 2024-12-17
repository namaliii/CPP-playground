/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:06 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/17 21:29:22 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.parseData(argv[1]);

	const std::map<std::string, float>& data = exchange.getDataMap();
	for (const auto& [date, value] : data) {
		std::cout << "Date: " << date << ", Value: " << value << std::endl;
	}

	return 0;
}
