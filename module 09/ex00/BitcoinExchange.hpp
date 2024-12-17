/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:08 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/17 21:48:04 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

// #define BLUE(text) "\033[38;5;32m" text "\033[0m"
// #define GREEN(text) "\033[38;5;28m" text "\033[0m"
// #define MAGENTA(text) "\033[38;5;213m" text "\033[0m"
// #define RED(text) "\033[38;5;160m" text "\033[0m"
// #define YELLOW(text) "\033[38;5;220m" text "\033[0m"

class BitcoinExchange {
	private:
		std::map<std::string, float> dataMap;
	public:
		BitcoinExchange() = default;
		BitcoinExchange(BitcoinExchange const & to_copy) = default;
		~BitcoinExchange() = default;
		BitcoinExchange& operator=(BitcoinExchange const & src) = default;

		void parseData(const char *fileName);
		static void trim(std::string &str);
		bool validateValue(const std::string& date,
			const std::string& str_value, float& to_float);
		bool validateDate(const std::string& date);

		static bool parseLine(const std::string &line, char separator,
			std::string &date, std::string &value);
		void loadData(const char *dataFile);
		void processInput(const char *inputFile);

		const std::map<std::string, float>& getDataMap() const;
};

#endif