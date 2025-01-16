/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:43:25 by anamieta          #+#    #+#             */
/*   Updated: 2025/01/16 21:01:33 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv) {
	this->vecInput = parseNumbers<std::vector<int>>(argc, argv);
	this->deqInput = parseNumbers<std::deque<int>>(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: deqPairs(other.deqPairs),
		deqMain(other.deqMain),
		deqAppend(other.deqAppend),
		deqInput(other.deqInput),
		vecPairs(other.vecPairs),
		vecMain(other.vecMain),
		vecAppend(other.vecAppend),
		vecInput(other.vecInput) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		deqPairs = other.deqPairs;
		deqMain = other.deqMain;
		deqAppend = other.deqAppend;
		deqInput = other.deqInput;

		vecPairs = other.vecPairs;
		vecMain = other.vecMain;
		vecAppend = other.vecAppend;
		vecInput = other.vecInput;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector() {
	std::vector<int> jacob;

	if (isSorted(vecInput)) {
		vecMain = vecInput;
		return;
	}
	if (vecInput.size() == 2) {
		vecMain = vecInput;
		if (!isSorted(vecMain))
			std::swap(vecMain[0], vecMain[1]);
		return;
  	}
	// Reserve memory to avoid multiple reallocations and improve performance
	vecPairs.reserve(vecInput.size() / 2);
	vecAppend.reserve(vecInput.size() / 2);

	for (size_t i = 0; i + 1 < vecInput.size(); i += 2) {
		std::vector<int> couple = { std::max(vecInput[i], vecInput[i + 1]), std::min(vecInput[i], vecInput[i + 1]) };
		vecPairs.push_back(couple);
	}
	mergeSortFirsts(vecPairs);
	for (auto& it : vecPairs) {
		vecMain.push_back(it[0]);
		vecAppend.push_back(it[1]);
	}
	if (vecInput.size() % 2 != 0) {
		vecAppend.push_back(vecInput.back());
	}
	jacob = generateJsthalNumbers<std::vector<int>>(vecAppend.size());
	doBinaryInsertion(vecMain, vecAppend, jacob);
}

void PmergeMe::sortDeque() {
	std::deque<int> jacob;

	if (isSorted(deqInput)) {
		deqMain = deqInput;
		return;
	}
	for (size_t i = 0; i + 1 < deqInput.size(); i += 2) {
		std::vector<int> couple = { std::max(deqInput[i], deqInput[i + 1]), std::min(deqInput[i], deqInput[i + 1]) };
		deqPairs.push_back(couple);
	}
	mergeSortFirsts(deqPairs);
	for (auto& it : deqPairs) {
		deqMain.push_back(it[0]);
		deqAppend.push_back(it[1]);
	}
	if (deqInput.size() % 2 != 0) {
		deqAppend.push_back(deqInput.back());
	}
	jacob = generateJsthalNumbers<std::deque<int>>(deqAppend.size());
	doBinaryInsertion(deqMain, deqAppend, jacob);
}

void PmergeMe::sortAndDisplay() {
		std::cout << "Before: ";
		displaySequence(vecInput);
		auto start = std::chrono::high_resolution_clock::now();
		sortVector();
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration<double, std::milli>(end - start);

		std::cout << "After: ";
		displaySequence(vecMain);
		std::cout << "Time to process a range of " << vecInput.size()
					<< " elements with std::vector: "
					<< std::fixed << std::setprecision(3)
					<< duration.count() << " ms" << std::endl;

		start = std::chrono::high_resolution_clock::now();
		sortDeque();
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration<double, std::milli>(end - start);

		std::cout << "Time to process a range of " << deqInput.size()
					<< " elements with std::deque: "
					<< std::fixed << std::setprecision(3)
					<< duration.count() << " ms" << std::endl;
}
