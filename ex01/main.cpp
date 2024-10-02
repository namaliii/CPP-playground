/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:50:16 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/02 20:43:44 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	std::cout << "~~~~~~~~~~~ WELCOME ~~~~~~~~~~~" << std::endl;
	std::cout << "~~~ TO MY AMAZING PHONEBOOK! ~~~" << std::endl;
	std::cout << "~~~~~~~~~~~ ENJOY! ~~~~~~~~~~~" << std::endl;
	std::cout << std::endl;
	std::cout << "To insert a contact use ADD, to search use SEARCH or just EXIT." << std::endl;
	std::cout << std::endl;
	while (true) {
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please use ADD, SEARCH or EXIT" << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
