/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:21:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/18 21:01:16 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	// std::cout << "Contact created" << std::endl;
}

Contact::~Contact() {
	// std::cout << "Contact destroyed" << std::endl;
}

std::string& Contact::getFirstName() {
	return this->firstName;
}

std::string& Contact::getLastName() {
	return this->lastName;
}

std::string& Contact::getNickname() {
	return this->nickname;
}

std::string& Contact::getPhoneNumber() {
	return this->phoneNumber;
}

void Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}
