/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:07:57 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/14 22:51:22 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	int a = 5;
	int b = 17;
	int c = 3;
	int d = 737;
	int e = 0;
	std::cout << YELLOW("\n* MutantStack operations (with ints) *\n") << std::endl;
	MutantStack<int> mstack;
	std::cout << GREEN("adding ") << a << GREEN(" on the top") << std::endl;
	mstack.push(a);
	std::cout << GREEN("adding ") << b << GREEN(" on the top") << std::endl;
	mstack.push(b);
	std::cout << BLUE("checking what's on top: ");
	std::cout << mstack.top() << std::endl;
	std::cout << RED("deleting the top!") << std::endl;
	mstack.pop();
	std::cout << BLUE("checking the current size: ");
	std::cout << mstack.size() << std::endl;
	std::cout << GREEN("adding ") << c << GREEN(" on the top") << std::endl;
	mstack.push(c);
	std::cout << GREEN("adding ") << a << GREEN(" on the top") << std::endl;
	mstack.push(a);
	std::cout << GREEN("adding ") << d << GREEN(" on the top") << std::endl;
	mstack.push(d);
	std::cout << GREEN("adding ") << e << GREEN(" on the top") << std::endl;
	mstack.push(e);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << MAGENTA("\ncontents of MutantStack: ");
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	std::cout << YELLOW("\n\n* Int list operations *\n") << std::endl;
	std::list<int> lst;
	std::cout << GREEN("adding ") << a << GREEN(" at the back") << std::endl;
	lst.push_back(a);
	std::cout << GREEN("adding ") << b << GREEN(" at the back") << std::endl;
	lst.push_back(b);
	std::cout << BLUE("checking what's at the back: ");
	std::cout << lst.back() << std::endl;
	std::cout << RED("deleting the back!") << std::endl;
	lst.pop_back();
	std::cout << BLUE("checking the current size: ");
	std::cout << lst.size() << std::endl;
	std::cout << GREEN("adding ") << c << GREEN(" at the back") << std::endl;
	lst.push_back(c);
	std::cout << GREEN("adding ") << a << GREEN(" at the back") << std::endl;
	lst.push_back(a);
	std::cout << GREEN("adding ") << d << GREEN(" at the back") << std::endl;
	lst.push_back(d);
	std::cout << GREEN("adding ") << e << GREEN(" at the back") << std::endl;
	lst.push_back(e);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	std::cout << MAGENTA("\ncontents of the list: ");
	while (lit != lite) {
		std::cout << *lit << " ";
		++lit;
	}
	std::cout << std::endl;

	std::string ananas = "ananas";
	std::string papaya = "papaya";
	std::string lichi = "lichi";
	std::cout << YELLOW("\n\n* String list operations *\n") << std::endl;
	std::list<std::string> str_lst;
	std::cout << GREEN("adding ") << papaya << GREEN(" at the front") << std::endl;
	str_lst.push_front(papaya);
	std::cout << GREEN("adding ") << ananas << GREEN(" at the front") << std::endl;
	str_lst.push_front(ananas);
	std::cout << BLUE("checking what's at the front: ");
	std::cout << str_lst.front() << std::endl;
	std::cout << RED("deleting the front!") << std::endl;
	str_lst.pop_front();
	std::cout << BLUE("checking the current size: ");
	std::cout << str_lst.size() << std::endl;
	std::cout << GREEN("adding ") << lichi << GREEN(" at the front") << std::endl;
	str_lst.push_front(lichi);

	std::list<std::string>::iterator str_lit = str_lst.begin();
	std::list<std::string>::iterator str_lite = str_lst.end();
	std::cout << MAGENTA("\ncontents of the string list: ");
	while (str_lit != str_lite) {
		std::cout << *str_lit << " ";
		++str_lit;
	}
	std::cout << "\n" << std::endl;
	return 0;
}

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }