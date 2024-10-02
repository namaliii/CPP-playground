/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:21:23 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/02 20:57:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// initialize contactCount right at the moment of the object's creation
PhoneBook::PhoneBook() : contactCount(0) {
	// std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook() {
	// std::cout << "PhoneBook destroyed" << std::endl;
}

int PhoneBook::getContactIndex() {
	return contactCount % 8;
}

bool PhoneBook::validatePhoneNumber(std::string& phoneNumber) {
	if (phoneNumber.empty() || (!std::isdigit(phoneNumber[0]) && phoneNumber[0] != '+'))
		return false;
	for (size_t i = 1; i < phoneNumber.length(); i++) {
		if (!std::isdigit(phoneNumber[i]))
			return false;
	}
	return true;
}

bool PhoneBook::validateAlpha(std::string& str) {
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isalpha(str[i]) && !std::isspace(str[i]))
			return false;
	}
	return true;
}

std::string PhoneBook::formatString(const std::string& str) {
	std::string formattedStr = str;
	if (str.length() > 10)
		formattedStr = str.substr(0, 9) + ".";
	return formattedStr;
}

std::string PhoneBook::inputField(const std::string& fieldName) {
	std::string input;
	while (input.empty()) {
		std::cout << "Enter " << fieldName << ": ";
		std::getline(std::cin, input);
	}
	return input;
}
