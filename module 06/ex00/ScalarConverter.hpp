/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:15:14 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/06 21:09:04 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
#include <stdexcept>

class ScalarConverter {
	private:
		ScalarConverter() {}
		~ScalarConverter() {}
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
	public:
		static void convert(const std::string& literal);
};

#endif