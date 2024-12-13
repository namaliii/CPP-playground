/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:02:20 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/13 23:33:28 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <list>

#define BLUE(text) "\033[38;5;32m" text "\033[0m"
#define GREEN(text) "\033[38;5;28m" text "\033[0m"
#define MAGENTA(text) "\033[38;5;213m" text "\033[0m"
#define RED(text) "\033[38;5;160m" text "\033[0m"
#define YELLOW(text) "\033[38;5;220m" text "\033[0m"

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	container;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span& operator=(const Span& rhs);

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	printContainer() const;

		template <typename Iterator>
		void 	addRange(Iterator begin, Iterator end) {
			if (std::distance(begin, end) > static_cast<int>(_N - container.size()))
				throw std::out_of_range("range exceeds maximum capacity of the Span!");
			container.insert(container.end(), begin, end);
		}
};


#endif