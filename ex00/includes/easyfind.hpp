#pragma once

#include <algorithm>

class NotFoundException : public std::exception {
public:
	const char *what() const throw() {
		return "Element not found in container";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find) {
	 typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	 if (it == container.end())
		throw NotFoundException();
	return it;
}