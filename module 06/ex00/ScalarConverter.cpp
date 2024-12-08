/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:15:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/08 17:28:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
	try {
		char	c;
		int		i;
		float	f;
		double	d;

		if (literal.length() == 1) {
			c = literal[0];
			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
			return;
		}
		if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
			return;
		} else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
			return;
		}
		if (literal.find('.') == std::string::npos) {
			i = std::stoi(literal);
			if (i >= 32 && i <= 126)
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "char: Non-displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
		} else {
			if (literal.back() == 'f') {
				f = std::stof(literal);
				d = static_cast<double>(f);
			} else {
				d = std::stod(literal);
				f = static_cast<float>(d);
			}
			if (d >= 32 && d <= 126)
				std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
			else
				std::cout << "char: Non-displayable" << std::endl;
			if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: Invalid literal" << std::endl;
	}
}
