/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:12 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/17 22:06:08 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::trim(std::string &str) {
	str.erase(0, str.find_first_not_of(" \t"));
	str.erase(str.find_last_not_of(" \t") + 1);
}

bool BitcoinExchange::validateValue(const std::string& date,
	const std::string& str_value, float& to_float) {
	try {
		to_float = std::stof(str_value);
		if (to_float < 0 || to_float > 1000) {
			std::cerr << "Error: value out of range for " << date << std::endl;
			return false;
		}
		return true;
	} catch (const std::exception&) {
		std::cerr << "Error: value for " << date << " is invalid!" << std::endl;
		return false;
	}
}

bool BitcoinExchange::validateDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << "Error: invalid date format: " << date << std::endl;
		return false;
	}

	try {
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (year < 1900 || year > 2100) {
			std::cerr << "Error: year out of range in date: " << date << std::endl;
			return false;
		}
		if (month < 1 || month > 12) {
			std::cerr << "Error: invalid month in date: " << date << std::endl;
			return false;
		}
		if (day < 1 || day > 31) {
			std::cerr << "Error: invalid day in date: " << date << std::endl;
			return false;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			std::cerr << "Error: invalid day in month for date: " << date << std::endl;
			return false;
		}
		if (month == 2) {
			bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
			if (day > 29 || (!leap && day > 28)) {
				std::cerr << "Error: invalid day in February for date: " << date << std::endl;
				return false;
			}
		}
		return true;
	} catch (const std::exception&) {
		std::cerr << "Error: invalid numeric values in date: " << date << std::endl;
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

void BitcoinExchange::loadData(const char *dataFile) {
	std::ifstream file(dataFile);
	if (!file.is_open()) {
		std::cerr << "Error: couldn't open the file!" << std::endl;
		return;
	}

	std::string line, date, value;
	while (std::getline(file, line)) {
		if (parseLine(line, ',', date, value)) {
			try {
				float rate = std::stof(value);
				if (validateDate(date) && validateValue(date, value, rate)) {
					dataMap[date] = rate;
				} else {
					std::cerr << "Error: invalid data in data.csv: " << line << std::endl;
				}
			} catch (const std::invalid_argument&) {
				std::cerr << "Error: can't convert string to float: "
					<< value << " for date: " << date << std::endl;
			} catch (const std::out_of_range&) {
				std::cerr << "Error: numeric value out of range for " << date
					<< ": " << value << std::endl;
			}
		}
	}
	file.close();
}

const std::map<std::string, float>& BitcoinExchange::getDataMap() const {
	return dataMap;
}