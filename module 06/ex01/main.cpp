/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:14:57 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/08 17:59:45 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data original = {42, "Hello, World!"};

	uintptr_t raw = Serializer::serialize(&original);

	Data* result = Serializer::deserialize(raw);
	std::cout << BLUE("\n* ADDRESSES *") << std::endl;
	std::cout << GREEN("Original address: ") << &original << std::endl;
	std::cout << GREEN("Deserialized address: ") << result << std::endl;
	std::cout << GREEN("\nRaw value: ") << raw << std::endl;
	std::cout << BLUE("\n* DESERIALIZED DATA *") << std::endl;
	std::cout << GREEN("Number: ") << result->number << std::endl;
	std::cout << GREEN("Text: ") << result->text << "\n" << std::endl;

	return 0;
}