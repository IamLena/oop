#pragma once
#include "vector.h"
#include <iostream>

template <typename T>
Vector<T>::Vector() {
	ptr = nullptr;
	std::cout << "created\n";
}

template <typename T>
Vector<T>::Vector(size_t size) : base::BaseContainer(size) {
	ptr = std::shared_ptr<T>(new T[size]);
	std::cout << "created\n";
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : base::BaseContainer(list.size()) {
	ptr = std::shared_ptr<T>(new T[list.size()]);
	T* run = ptr.get();
	for (auto element : list) {
		*run = element;
		run += 1;
	}
}

template <typename T>
Vector<T>::~Vector() {
	std::cout << "deleted\n";
}

template <typename T>
base::Iterator<T> Vector<T>::begin() {
	base::Iterator<T> iter(this->get_size(), ptr);
	return iter;
}
template <typename T>
base::Iterator<T> Vector<T>::end() {
	base::Iterator<T> iter(this->get_size(), ptr);
	iter += this->get_size();
	return iter;
}