#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "Colors.hpp"

class Span {
public:
	explicit Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);

	void addNumber(int nb);
	int shortestSpan() const;
	int longestSpan() const;

	void addRange(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);

	unsigned int getSize() const;

	void printStorage(int width) const;

    ~Span();

class FullStorageException : public std::exception {
public:
	const char *what() const throw();
};
class NoSpanFound : public std::exception {
public:
	const char *what() const throw();
};

private:
	Span();
	unsigned int _size;
	std::vector<int> _storage;
};
