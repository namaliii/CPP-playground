#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <chrono>

class PmergeMe {
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sort_and_display();

	private:
		std::vector<int> vec;
		std::list<int> lst;

		void ford_johnson_merge_insertion(std::vector<int>& vec);
		void ford_johnson_merge_insertion(std::list<int>& lst);
		void handle_error() const;
};

template <typename Container>
void display_sequence(const Container& container) {
	for (const auto& num : container) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

#endif