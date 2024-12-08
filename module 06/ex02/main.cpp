/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:11:24 by anamieta          #+#    #+#             */
/*   Updated: 2024/12/08 18:45:09 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "InheritingClasses.hpp"

Base* generate(void) {
	int randVal = rand() % 3;

	if (randVal == 0) {
		return new A();
	} else if (randVal == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "This object is of class A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "This object is of class B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "This object is of class C" << std::endl;
	} else
		std::cout << "BOBER" << std::endl;
}

void identify(Base& p) {
	if (dynamic_cast<A*>(&p)) {
		std::cout << "This object is of class A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(&p)) {
		std::cout << "This object is of class B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(&p)) {
		std::cout << "This object is of class C" << std::endl;
		return;
	}
	std::cout << "This object does not belong to any of the A, B, C classes." << std::endl;
}

int main(void) {
	srand(time(0));
	Base* ptr1 = generate();
	Base* ptr2 = generate();
	Base* ptr3 = generate();

	Base& ref1 = *ptr1;
	Base& ref2 = *ptr2;
	Base& ref3 = *ptr3;

	Base* invalid = nullptr;

	std::cout << GREEN("Identifying objects using pointers:\n");
	identify(ptr1);
	identify(ptr2);
	identify(ptr3);

	std::cout << BLUE("\nIdentifying objects using references:\n");
	identify(ref1);
	identify(ref2);
	identify(ref3);

	std::cout << RED("\nTrying to identify invalid object:\n");
	identify(invalid);

	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}
