/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:12 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/17 17:26:53 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	if (!parseData(argv))
		return 1;
	return 0;
}

void trim(std::string &str) {
	str.erase(0, str.find_first_not_of(" \t"));
	str.erase(str.find_last_not_of(" \t") + 1);
}

void parseData(char **argv) {
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << "Error: couldn't open the file!" << std::endl;
		return;
	}
	std::map<std::string, float> dataMap;
	std::string line;
	while (std::getline(file, line)) {
		size_t pipe_pos = line.find(',');
		if (pipe_pos != std::string::npos) {
			std::string date = line.substr(0, pipe_pos);
			std::string value = line.substr(pipe_pos + 1);

			trim(date);
			trim(value);
			try {
				float btc_value = std::stof(value);
				if (btc_value >= 0 && btc_value <= 1000)
					dataMap[date] = btc_value;
				else
					std::cerr << "Error: value out of range for " << date
						<< std::endl;

				} catch (const std::exception& e) {
					std::cerr << "Error: value for " << date << " is invalid!"
						<< std::endl;
				}
		} else {
			std::cerr << "Error: invalid line format!";
		}
	}
	file.close();
}

