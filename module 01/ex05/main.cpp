/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:02:06 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/25 21:24:35 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("INVALID");
    return 0;
}