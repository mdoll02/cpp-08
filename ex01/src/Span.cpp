#include "Span.hpp"
#include <climits>

Span::Span() {
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _size(n){
	std::cout << "Span parameter constructor called" << std::endl;
	_storage.reserve(n);
}

Span::Span(const Span &other) {
	std::cout << "Span copy constructor called" << std::endl;
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_size = other._size;
		this->_storage.clear();
		this->_storage.reserve(_size);
		for (std::vector<int>::const_iterator it = other._storage.begin(); it < other._storage.end(); ++it) {
			this->_storage.push_back(*it);
		}
	}
	return *this;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int nb) {
	if (_storage.size() == _size)
		throw FullStorageException();
	_storage.push_back(nb);
}

void Span::addRange(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end) {
	if (_storage.size() == _size || (end - start) + _storage.size() > _size)
		throw FullStorageException();
	_storage.insert(_storage.end(), start, end);
}

unsigned int Span::getSize() const {
	return _storage.size();
}

void Span::printStorage(int width) const {
	int count = 0;

	for (std::vector<int>::const_iterator it = _storage.begin(); it < _storage.end(); it++) {
		std::cout << YELLOW << *it << " " << R;

		if (++count == width) {
			std::cout << std::endl;
			count = 0;
		}
	}
	if (count > 0)
		std::cout << std::endl;
}

int Span::shortestSpan() const {
	if (_storage.size() <= 1)
		throw NoSpanFound();
	int shortest = INT_MAX;

	std::vector<int> tmp_storage = _storage;
	std::sort(tmp_storage.begin(), tmp_storage.end());
	for (std::vector<int>::const_iterator it = tmp_storage.begin(); it + 1 < tmp_storage.end(); it++) {
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
	}
	return shortest;
}

int Span::longestSpan() const {
	if (_storage.size() <= 1)
		throw NoSpanFound();

	int min_element = *std::min_element(_storage.begin(), _storage.end());
	int max_element = *std::max_element(_storage.begin(), _storage.end());


	// std::cout << "min: " << min_element << " max: " << max_element << std::endl;
	return max_element - min_element;
}

const char *Span::FullStorageException::what() const throw() {
	return "Storage will overflow";
}

const char *Span::NoSpanFound::what() const throw() {
	return "No Span can be found";
}
