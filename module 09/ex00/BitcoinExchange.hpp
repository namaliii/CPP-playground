/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:08 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/19 15:56:46 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <limits>
#include <cmath>

#define RED(text) "\033[38;5;160m" << text << "\033[0m"
#define GREEN(text) "\033[38;5;28m" << text << "\033[0m"

class BitcoinExchange {
	public:
		BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange& other) = default;
		BitcoinExchange& operator=(const BitcoinExchange& other) = default;
		~BitcoinExchange() = default;
		
		void loadData(const char *dataFile);
		void processInputFile(const char *inputFile);

	private:
		std::map<std::string, double> dataMap;

		void trim(std::string &str);
		bool validateValue(const std::string& str_value, double& to_double);
		bool validateDate(const std::string& date);
		bool parseLine(const std::string& line, char delimiter, std::string& date, std::string& value);
		std::string findClosestDate(const std::string& date) const;
};

#endif