/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:52:10 by anamieta          #+#    #+#             */
/*   Updated: 2025/01/10 20:52:11 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
	if (argc < 2) {
		handle_error();
	}

	for (int i = 1; i < argc; ++i) {
		try {
			int num = std::stoi(argv[i]);
			if (num <= 0) {
				std::cerr << "Invalid input: " << argv[i] << " (must be a positive integer)" << std::endl;
				handle_error();
			}
			vec.push_back(num);
			lst.push_back(num);
		} catch (const std::invalid_argument& e) {
			std::cerr << "Invalid input: " << argv[i] << " (not a valid integer)" << std::endl;
			handle_error();
		}
	}
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: vec(other.vec), lst(other.lst) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		vec = other.vec;
		lst = other.lst;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort_and_display() {
	std::cout << "Before: ";
	display_sequence(vec);

	// Warm-up run
	std::vector<int> vec_copy = vec;
	ford_johnson_merge_insertion(vec_copy);

	// Measure time for std::vector
	auto start = std::chrono::high_resolution_clock::now();
	ford_johnson_merge_insertion(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double, std::micro>(end - start);

	std::cout << "After: ";
	display_sequence(vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << duration.count() << " us" << std::endl;

	// Warm-up run
	std::list<int> lst_copy = lst;
	ford_johnson_merge_insertion(lst_copy);

	// Measure time for std::list
	start = std::chrono::high_resolution_clock::now();
	ford_johnson_merge_insertion(lst);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<double, std::micro>(end - start);

	std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << std::fixed << std::setprecision(6) << duration.count() << " us" << std::endl;
}

void PmergeMe::ford_johnson_merge_insertion(std::vector<int>& vec) {
	if (vec.size() <= 10) {
		std::sort(vec.begin(), vec.end());
		return;
	}

	size_t mid = vec.size() / 2;
	std::vector<int> left(vec.begin(), vec.begin() + mid);
	std::vector<int> right(vec.begin() + mid, vec.end());

	ford_johnson_merge_insertion(left);
	ford_johnson_merge_insertion(right);

	std::vector<int> merged;
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));

	vec = merged;
}

void PmergeMe::ford_johnson_merge_insertion(std::list<int>& lst) {
	if (lst.size() <= 10) {
		lst.sort();
		return;
	}

	size_t mid = lst.size() / 2;
	std::list<int> left, right;

	auto it = lst.begin();
	for (size_t i = 0; i < mid; ++i) {
		left.push_back(*it);
		++it;
	}

	for (size_t i = mid; it != lst.end(); ++i) {
		right.push_back(*it);
		++it;
	}

	ford_johnson_merge_insertion(left);
	ford_johnson_merge_insertion(right);

	lst.clear();
	lst.merge(left);
	lst.merge(right);
}

void PmergeMe::handle_error() const {
	std::cerr << "Error" << std::endl;
	exit(1);
}