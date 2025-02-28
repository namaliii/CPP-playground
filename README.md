# C++ Projects Repository

## Overview

This repository contains various C++ projects organized into modules. Each module consists of multiple exercises that demonstrate different aspects of C++ programming, including object-oriented programming, templates, and more.

## Repository Structure

The repository is organized into the following modules:

- **module 00**
  - `ex00`: Basic C++ program with a `Makefile` and `megaphone.cpp`.
  - `ex01`: Simple phone book application with classes `Contact` and `PhoneBook`.

- **module 01**
  - `ex00` to `ex06`: Various exercises including classes, inheritance, and polymorphism.

- **module 02**
  - `ex00` to `ex02`: Exercises focusing on fixed-point arithmetic and other concepts.

- **module 03**
  - `ex00` to `ex03`: Exercises on inheritance, including `ClapTrap`, `ScavTrap`, `FragTrap`, and `DiamondTrap`.

- **module 04**
  - `ex00` to `ex03`: Advanced exercises on polymorphism, abstract classes, and more.

- **module 05**
  - `ex00` to `ex03`: Exercises on forms and bureaucrats, including `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`.

- **module 06**
  - `ex00` to `ex02`: Focuses on serialization, including converting objects to storable formats, handling complex data structures, ensuring data integrity, and practical applications such as saving and loading game states or configuration settings.

- **module 07**
  - `ex00` to `ex02`: Template programming and other advanced C++ features.

- **module 08**
  - `ex00` to `ex02`: Exercises on containers and algorithms.

- **module 09**
  - `ex00`: A project related to Bitcoin transactions, focusing on understanding and implementing the basics of blockchain technology, transaction validation, and cryptographic hashing.
  - `ex01`: Implementation of Reverse Polish Notation (RPN) calculator, which evaluates mathematical expressions written in postfix notation, a method used in stack-based and some programming languages.
  - `ex02`: Implementation of the Ford-Johnson algorithm, which is an efficient sorting algorithm that combines merge sort and insertion sort to achieve optimal sorting times for small arrays.

## Example Code

Here is an example of a class definition from `module 04/ex01/Animal.cpp`:

```cpp
#include "Animal.hpp"

Animal::Animal() {
    // Constructor implementation
}

Animal::Animal(const Animal &copy) : type(copy.type) {
    // Copy constructor implementation
}

Animal::~Animal() {
    // Destructor implementation
}

Animal& Animal::operator=(const Animal& rhs) {
    // Assignment operator implementation
}

std::string Animal::getType() const {
    // Getter for type
}

void Animal::makeSound() const {
    // Virtual function for making sound
}
```
## **How to Build**
Each exercise contains a Makefile for building the project. To build a specific exercise, navigate to the exercise directory and run:

```bash
make
```
For example, to build module 00/ex00, use:

```bash
cd module 00/ex00
make
```
## **License**
This repository is licensed under the MIT License. See the LICENSE file for more information.

## **Contact**
For any questions or inquiries, please contact the repository owner at anamieta@student.42heilbronn.de

Note: This repository is part of the 42 school curriculum and contains exercises and projects designed to teach and test various C++ programming concepts.
