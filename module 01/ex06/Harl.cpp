/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:10:03 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/27 22:03:49 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getLevelIndex(const std::string& level) {
	if (level == "DEBUG") return 0;
	if (level == "INFO") return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR") return 3;
	return -1;
}

void Harl::complain(std::string level) {
	void (Harl::*complaints[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*complaints[i])();
			std::cout << std::endl;
			return;
		}
	}
	std::cout << "Invalid complaint level" << std::endl;
}

void Harl::filterComplaints(const std::string &level) {
	int levelIndex = getLevelIndex(level);

	if (levelIndex == -1) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	for (int i = 0; i <= levelIndex; ++i) {
		switch (i) {
			case 0:
				std::cout << "[ DEBUG ]" << std::endl;
				this->debug();
				break;
			case 1:
				std::cout << "[ INFO ]" << std::endl;
				this->info();
				break;
			case 2:
				std::cout << "[ WARNING ]" << std::endl;
				this->warning();
				break;
			case 3:
				std::cout << "[ ERROR ]" << std::endl;
				this->error();
				break;
		}
	}
}
