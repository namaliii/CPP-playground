/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:02:45 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/02 19:23:10 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook {
	private:
	Contact	contacts[8];
	int	contactCount;
	int	getContactIndex();

	bool validatePhoneNumber(std::string& phoneNumber);
	bool validateAlpha(std::string& str);
	std::string formatString(const std::string& str);
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();
	std::string inputField(const std::string& fieldName);
};

#endif