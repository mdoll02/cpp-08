#pragma once

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {
	//std::cout << "Default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack() {
	//std::cout << "Destructor called" << std::endl;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
	std::stack<T>::operator=(other);
	return *this;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rend() {
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();
}