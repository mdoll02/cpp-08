#pragma once

#include <algorithm>

class NotFoundException : public std::exception {
public:
	const char *what() const throw() {
		return "Element not found in container";
	}
};

template <typename T>
typename T::const_iterator easyfind(T &container, int to_find) {
	 typename T::const_iterator it = std::find(container.begin(), container.end(), to_find);
	 if (it == container.end())
		throw NotFoundException();
	return it;
}