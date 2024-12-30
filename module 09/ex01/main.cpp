#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED("Please insert 2 args!\n \
		./executableName followed by mathematical expression in Reverse Polish Notation, i.e. \"29+6*\"") << std::endl;
		return 1;
	}

	RPN rpn;
	try {
		int result = rpn.calculate(argv[1]);
		std::cout << GREEN("Result: " << result) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED("Error: " << e.what()) << std::endl;
		return 1;
	}
	return 0;
}

