# C++ Projects Repository

## Overview

This repository contains various C++ projects organized into modules. Each module consists of multiple exercises that demonstrate different aspects of C++ programming, including object-oriented programming, templates, and more.

## Repository Structure

The repository is organized into the following modules:
- **module 00**
  - `ex00` to `ex01`: Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and other basic concepts.

- **module 01**
  - `ex00` to `ex06`: Memory allocation, pointers to members, references, and switch statements.

- **module 02**
  - `ex00` to `ex02`: Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Class Form.

- **module 03**
  - `ex00` to `ex03`: Exercises on inheritance.

- **module 04**
  - `ex00` to `ex03`: Subtype polymorphism, abstract classes, and interfaces.

- **module 05**
  - `ex00` to `ex03`: Repetition and exceptions.

- **module 06**
  - `ex00` to `ex02`: Focus on serialization, including converting objects to storable formats, handling complex data structures, ensuring data integrity, and practical applications such as saving and loading game states or configuration settings. (or something related to C++ casts)

- **module 07**
  - `ex00` to `ex02`: Template programming.

- **module 08**
  - `ex00` to `ex02`: Templated containers, iterators, and algorithms.

- **module 09**
  Project focused on STL (Standard Template Library), which is a collection of template classes and functions in C++ designed to provide general-purpose data structures (e.g., vectors, lists, maps) and algorithms (e.g., sorting, searching). It allows programmers to work with data more efficiently, without the need to implement these structures and algorithms manually.

  - `ex00`: A project related to Bitcoin transactions, focusing on understanding and implementing the basics of blockchain technology, transaction validation, and cryptographic hashing.
  - `ex01`: Implementation of a Reverse Polish Notation (RPN) calculator, which evaluates mathematical expressions written in postfix notation, a method used in stack-based and some programming languages.
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
