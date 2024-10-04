/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:21:23 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/04 18:39:44 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {
	// std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook() {
	// std::cout << "PhoneBook destroyed" << std::endl;
}

int PhoneBook::getContactIndex() {
	return contactCount % MAX_CONTACT;
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

void PhoneBook::addContact() {
	int index = getContactIndex();
	std::cout << "Adding new contact at index: " << index + 1 << std::endl;
	contacts[index].setFirstName(inputField("first name"));
	contacts[index].setLastName(inputField("last name"));
	contacts[index].setNickname(inputField("nickname"));
	std::string phoneNumber;
	do {
		phoneNumber = inputField("phone number");
		if (!validatePhoneNumber(phoneNumber))
			std::cout << "Invalid phone number. Please enter a valid phone number." << std::endl;
	} while (!validatePhoneNumber(phoneNumber));
	contacts[index].setPhoneNumber(phoneNumber);
	contacts[index].setDarkestSecret(inputField("darkest secret"));
	contactCount++;
}

void PhoneBook::searchContact() {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < MAX_CONTACT; i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << formatString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatString(contacts[i].getNickname()) << std::endl;
	}
	std::string input;
	std::cout << "Enter index of the contact you want to see: ";
	std::getline(std::cin, input);
	if (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit)) {
        std::cout << "Error: invalid index input" << std::endl;
        return ;
    }
	int index = std::stoi(input) - 1;
	if (index >= 0 && index < std::min(contactCount, MAX_CONTACT)) {
		std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	} else {
		std::cout << "Index invalid" << std::endl;
	}
}
