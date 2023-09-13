#include "Colors.hpp"
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::vector<int> vi(10);

	for (int i = 0; i < 10; i++)
		vi.push_back(i);
	try {
		::easyfind(vi, 5);
		std::cout << GREEN << "Found 5 in vi" << R << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "ERROR: " << e.what() << R << std::endl;
	}
	try {
		::easyfind(vi, 99);
		std::cout << GREEN << "Found 99 in vi" << R << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "ERROR: " << e.what() << R << std::endl;
	}

	std::list<int> li(10);

	for (int i = 0; i < 10; i++)
		li.push_back(i);
	try {
		::easyfind(li, 3);
		std::cout << GREEN << "Found 3 in li" << R << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "ERROR: " << e.what() << R << std::endl;
	}
	try {
		::easyfind(li, 19023);
		std::cout << GREEN << "Found 19023 in li" << R << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "ERROR: " << e.what() << R << std::endl;
	}
	return 0;
}