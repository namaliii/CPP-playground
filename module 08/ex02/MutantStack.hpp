/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:02:20 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/16 23:26:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <stdexcept>

#define BLUE(text) "\033[38;5;32m" text "\033[0m"
#define GREEN(text) "\033[38;5;28m" text "\033[0m"
#define MAGENTA(text) "\033[38;5;213m" text "\033[0m"
#define RED(text) "\033[38;5;160m" text "\033[0m"
#define YELLOW(text) "\033[38;5;220m" text "\033[0m"

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack<T>& src) : std::stack<T>(src) {}
		~MutantStack() {}
		MutantStack<T>& operator=(const MutantStack<T>& rhs) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}

		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
};


#endif