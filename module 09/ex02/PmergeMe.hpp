/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:52:16 by anamieta          #+#    #+#             */
/*   Updated: 2025/01/16 21:04:57 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>

#define RED(text) "\033[38;5;160m" << text << "\033[0m"

class PmergeMe {
	private:
		std::deque<std::vector<int>> deqPairs;
		std::deque<int> deqMain;
		std::deque<int> deqAppend;
		std::deque<int> deqInput;

		std::vector<std::vector<int>> vecPairs;
		std::vector<int> vecMain;
		std::vector<int> vecAppend;
		std::vector<int> vecInput;

		void sortVector();
		void sortDeque();

	public:
		PmergeMe();
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sortAndDisplay();
};

#include "PmergeMe.tpp"

#endif
