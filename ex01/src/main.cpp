#include "Span.hpp"
#include "Colors.hpp"
#include <iostream>

int main() {
	std::srand(time(NULL));
	std::cout << CYAN << "TEST 1" << R << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printStorage(10);
		try {
			std::cout << GREEN << "Size of the Vector: " << sp.getSize() << R << std::endl;
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << RED << "ERROR: " << e.what() << R << std::endl;
		}
	}
	std::cout << CYAN << "TEST 2" << R << std::endl;
	{
		Span sp = Span(10000);
		for (int i = 0; i < 10000; i++) {
			try {
				sp.addNumber(std::rand());
			}
			catch (std::exception &e) {
				std::cerr << RED << "ERROR: " << e.what() << R << std::endl;
			}
		}
		//sp.printStorage(30);
		try {
			std::cout << GREEN << "Size of the Vector: " << sp.getSize() << R << std::endl;
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << RED << "ERROR: " << e.what() << R << std::endl;
		}
	}
	std::cout << CYAN << "TEST 3" << R << std::endl;
	{
		Span sp = Span(10000);

		std::vector<int>vec(10000);
		std::generate(vec.begin(), vec.end(), std::rand);
		std::sort(vec.begin(), vec.end());

		try {
			sp.addRange(vec.begin(), vec.end());
		}
		catch (std::exception &e) {
			std::cerr << RED << "ERROR: " << e.what() << std::endl;
		}
		//sp.printStorage(30);
		try {
			std::cout << GREEN << "Size of the Vector: " << sp.getSize() << R << std::endl;
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << RED << "ERROR: " << e.what() << R << std::endl;
		}

	}
	return 0;
}