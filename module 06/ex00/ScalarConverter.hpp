/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:15:14 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/09 21:56:38 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
#include <stdexcept>

#define RED(text) "\033[38;5;160m" text "\033[0m"
#define GREEN(text) "\033[38;5;28m" text "\033[0m"

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
	public:
		static void convert(const std::string& literal);
};

#endif