/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:38:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/21 21:38:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		for (int j = 0; j < arg.length(); j++) {
			arg[j] = (toupper(arg[j]));
		}
		std::cout << arg;
		if (argc != i - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
