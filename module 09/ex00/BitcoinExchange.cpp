/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:12 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/18 22:40:42 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::trim(std::string &str) {
	str.erase(0, str.find_first_not_of(" \t"));
	str.erase(str.find_last_not_of(" \t") + 1);
}

bool BitcoinExchange::validateValue(const std::string& str_value, float& to_float) {
	try {
		to_float = std::stof(str_value);
		if (to_float < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			return false;
		}
		if (to_float > std::numeric_limits<int>::max()) {
			std::cerr << "Error: too large a number." << std::endl;
			return false;
		}
		return true;
	} catch (const std::exception&) {
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

bool BitcoinExchange::parseLine(const std::string &line, char separator,
	std::string &date, std::string &value) {
	size_t sep_pos = line.find(separator);
	if (sep_pos == std::string::npos) {
		std::cerr << "Error: invalid line format: " << line << std::endl;
		return false;
	}
	date = line.substr(0, sep_pos);
	value = line.substr(sep_pos + 1);
	trim(date);
	trim(value);
	return true;
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
		std::cerr << "Error: couldn't open the file!" << std::endl;
		return;
	}

	std::string line, date, value;
	while (std::getline(file, line)) {
		if (parseLine(line, ',', date, value)) {
			if (validateDate(date)) {
				float rate = 0.0f;
				if (validateValue(value, rate)) {
					dataMap[date] = rate;
				}
			}
		}
	}
	file.close();
}

void BitcoinExchange::processInputFile(const char *inputFile) {
	std::ifstream file(inputFile);
	if (!file.is_open()) {
		std::cerr << "Error: couldn't open the file!" << std::endl;
		return;
	}

	std::string line, date, value;
	while (std::getline(file, line)) {
		if (parseLine(line, '|', date, value)) {
			if (!validateDate(date)) {
				std::cerr << "Error: invalid date format: " << date << std::endl;
				continue;
			}
			try {
				auto it = dataMap.find(date);
				if (it == dataMap.end()) {
					date = findClosestDate(date);
					it = dataMap.find(date);
				}
				if (it != dataMap.end()) {
					float amount = std::stof(value);
					float result = amount * it->second;
					std::cout << date << " => " << value << " = " << result << std::endl;
				} else {
					std::cerr << "Error: no data available for date: " << date << std::endl;
				}
			} catch (const std::exception&) {
				std::cerr << "Error: invalid numeric value in input: " << line << std::endl;
			}
		} else {
			std::cerr << "Error: invalid line format in input: " << line << std::endl;
		}
	}
	file.close();
}


const std::map<std::string, float>& BitcoinExchange::getDataMap() const {
	return dataMap;
}
