#include"bchecker.h"
#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	if (BraceChecker::isBalanced(s)) {
		std::cout << "Balanced" << std::endl;
	}
	else {
		std::cout << "not Balanced" << std::endl;
	}
	return 0;
}