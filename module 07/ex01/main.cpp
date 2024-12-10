/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:20:13 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/10 21:36:20 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void printElement(T& element) {
	std::cout << element << " ";
}

template <typename T>
void doubleValue(T& value) {
	value *= 2;
}

template <>
void doubleValue(std::string& element) {
	element += element;
}

template <typename T>
void divideValue(T& value) {
	value /= 10;
}

void capitalizeStr(std::string & str) {
	for (std::string::iterator i = str.begin(); i != str.end(); ++i) {
		*i = std::toupper(*i);
	}
}

int main(void) {
	//testing for int array
	int arrInt[] = {1, 3, 6, 8, 9, 11};
	size_t lenInt = sizeof(arrInt) / sizeof(arrInt[0]);
	std::cout << GREEN("Original int array: ");
	iter(arrInt, lenInt, printElement<int>);
	iter(arrInt, lenInt, doubleValue<int>);
	std::cout << GREEN("\nInt array after doubling it: ");
	iter(arrInt, lenInt, printElement<int>);
	std::cout << "\n" << std::endl;

	//testing with a vector
	std::vector<int> vecInt = {20, 40, 68, 110};
	std::cout << YELLOW("Original vector: ");
	iter(vecInt.data(), vecInt.size(), printElement<int>);
	iter(vecInt.data(), vecInt.size(), divideValue<int>);
	std::cout << YELLOW("\nVector after dividing it by 10: ");
	iter(vecInt.data(), vecInt.size(), printElement<int>);
	std::cout << "\n" << std::endl;

	//testing for string array
	std::string arrStr[] = {"pam", "bam", "foo", "koko"};
	size_t lenStr = sizeof(arrStr) / sizeof(arrStr[0]);
	std::cout << BLUE("Original string array: ");
	iter(arrStr, lenStr, printElement<std::string>);
	iter(arrStr, lenStr, doubleValue<std::string>);
	std::cout << BLUE("\nString array after doubling it: ");
	iter(arrStr, lenStr, printElement<std::string>);
	std::cout << BLUE("\nString array after capitalizing it: ");
	iter(arrStr, lenStr, capitalizeStr);
	iter(arrStr, lenStr, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}