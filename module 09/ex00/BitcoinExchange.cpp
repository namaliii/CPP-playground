/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:12 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/19 16:24:10 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::trim(std::string &str) {
	str.erase(0, str.find_first_not_of(" \t"));
	str.erase(str.find_last_not_of(" \t") + 1);
}

bool BitcoinExchange::validateValue(const std::string& str_value, double& to_double) {
	try {
		if (str_value.empty()) {
			std::cerr << RED("Error: value is missing.") << std::endl;
			return false;
		}
		size_t pos;
		to_double = std::stof(str_value, &pos);
		if (pos != str_value.size()) {
			std::cerr << RED("Error: not a valid number.") << std::endl;
			return false;
		}
		if (to_double < 0) {
			std::cerr << RED("Error: not a positive number.") << std::endl;
			return false;
		}
		if (to_double > std::numeric_limits<int>::max()) {
			std::cerr << RED("Error: too large a number.") << std::endl;
			return false;
		}
		return true;
	} catch (const std::exception&) {
		std::cerr << RED("Error: not a valid number.") << std::endl;
		return false;
	}
}

bool BitcoinExchange::validateDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	try {
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (year < 1900 || year > 2100) { return false; }
		if (month < 1 || month > 12) { return false; }
		if (day < 1 || day > 31) { return false; }
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			return false;
		}
		if (month == 2) {
			bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
			if (day > 29 || (!leap && day > 28)) {
				return false;
			}
		}
		return true;
	} catch (const std::exception&) {
		return false;
	}
}

bool BitcoinExchange::parseLine(const std::string& line, char delimiter, std::string& date, std::string& value) {
	std::istringstream stream(line);
	if (std::getline(stream, date, delimiter) && std::getline(stream, value)) {
		trim(date);
		trim(value);
		return true;
	}
	return false;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
	auto it = dataMap.lower_bound(date);

	if (it != dataMap.end() && it->first == date) {
		return it->first;
	}
	if (it == dataMap.begin()) {
		return it->first;
	} else {
		auto prev = std::prev(it);
		if (it == dataMap.end() || std::abs(std::stoi(it->first.substr(0, 4)) - std::stoi(date.substr(0, 4))) < std::abs(std::stoi(prev->first.substr(0, 4)) - std::stoi(date.substr(0, 4)))) {
			return it->first;
		}
		return prev->first;
	}
}

void BitcoinExchange::loadData(const char *dataFile) {
	std::ifstream file(dataFile);
	if (!file.is_open()) {
		std::cerr << RED("Error: couldn't open the file!") << std::endl;
		return;
	}
	std::string line, date, value;
	while (std::getline(file, line)) {
		if (parseLine(line, ',', date, value)) {
			if (line.empty() || line == "date,exchange_rate")
				continue;
			try {
				double rate = std::stof(value);
				dataMap[date] = rate;
			} catch (const std::exception& e) {
				std::cerr << RED("data.csv value exception caught: ") << e.what() << std::endl;
			}
		}
	}
	file.close();
}

void BitcoinExchange::processInputFile(const char *inputFile) {
	std::ifstream file(inputFile);
	if (!file.is_open()) {
		std::cerr << RED("Error: couldn't open the file!") << std::endl;
		return;
	}

	std::string line, date, value;
	while (std::getline(file, line)) {
		if (line.empty() || line == "date | value")
			continue;
		if (parseLine(line, '|', date, value)) {
			if (validateDate(date)) {
				auto it = dataMap.find(date);
				if (it == dataMap.end()) {
					date = findClosestDate(date);
					it = dataMap.find(date);
				}
				if (it != dataMap.end()) {
					double amount = 0.0f;
					if (validateValue(value, amount)) {
						double result = amount * it->second;
						std::cout << GREEN(date) << GREEN(" => ") << GREEN(value) << GREEN(" = ") << GREEN(result) << std::endl;
					}
				} else {
					std::cerr << RED("Error: no data available for date: ") << date << std::endl;
				}
			} else {
				std::cerr << RED("Error: bad input => ") << RED(date) << std::endl;
			}
		} else {
			std::cerr << RED("Error: bad input => ") << RED(line) << std::endl;
		}
	}
	file.close();
}