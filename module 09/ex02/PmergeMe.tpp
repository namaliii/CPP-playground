/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:23:49 by anamieta          #+#    #+#             */
/*   Updated: 2025/01/16 18:36:11 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
Container parseNumbers(int argc, char **argv) {
	Container container;
	for (int i = 1; i < argc; i++) {
		std::istringstream stream(argv[i]);
		int num;

		stream >> num;
		if (num < 0 || stream.fail() || !stream.eof()) {
			throw std::invalid_argument("Invalid argument: '" + std::string(argv[i]) + "'");
		}
		container.push_back(num);
	}
	return container;
}

template <typename Container>
bool isSorted(const Container &container) {
	for (size_t i = 0; i < container.size() - 1; i++) {
		if (container[i] > container[i + 1])
			return false;
	}
	return true;
}

template <typename Container>
void mergeSortFirsts(Container &pairs) {
	if (pairs.size() <= 1)
		return;

	size_t mid = pairs.size() / 2;

	Container left(pairs.begin(), pairs.begin() + mid);
	Container right(pairs.begin() + mid, pairs.end());

	mergeSortFirsts(left);
	mergeSortFirsts(right);
	std::merge(left.begin(), left.end(), right.begin(),
				right.end(), pairs.begin());
}

template <typename Container>
void displaySequence(Container& container) {
	for (auto& num : container) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
void doBinaryInsertion(Container &main, Container &append, Container &jacob) {
	main.insert(main.begin(), append[0]);
	if (append.size() > 1 && jacob.size() > 1) {
		auto it = std::lower_bound(main.begin(), main.end(), append[1]);
		main.insert(it, append[1]);
	}
	for (size_t i = 2; i < jacob.size(); i++) {
		size_t prev = jacob[i - 1];
		size_t curr = jacob[i];
		if (curr > append.size() - 1)
			curr = append.size() - 1;
		while (curr > prev) {
			auto it = std::lower_bound(main.begin(), main.end(), append[curr]);
			main.insert(it, append[curr]);
			--curr;
		}
	}
}

template <typename Container>
	Container generateJsthalNumbers(const int size) {
	Container jacob;

	if (size > 0)
		jacob.push_back(0);
	if (size > 1)
		jacob.push_back(1);
	int i = 2;
	while (true) {
		int next_number = jacob[i - 1] + 2 * jacob[i - 2];
		jacob.push_back(next_number);
		if (size < next_number) break;
		i++;
	}
	return jacob;
}
