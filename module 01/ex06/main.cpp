/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:09:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/28 13:51:49 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// **SWITCH**
// Adding a new case often requires modifying existing code, which can lead to
// unintended bugs and disrupt existing functionality.
// Similar actions in different cases can lead to code duplication,
// violating the DRY (Don't Repeat Yourself) principle and
// making it difficult to update shared logic.

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <complaint level>" << std::endl;
		return 1;
	}
	Harl harl;
	std::string level = argv[1];
	harl.filterComplaints(level);
	return 0;
}
