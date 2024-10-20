/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:02:45 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/20 19:09:18 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

# define MAX_CONTACT 8

class PhoneBook {
	private:
		Contact contacts[MAX_CONTACT];
		int contactCount;
		int getContactIndex();
		bool validatePhoneNumber(std::string& phoneNumber);
		std::string formatString(const std::string& str);
		std::string inputField(const std::string& fieldName);
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact();
};

#endif