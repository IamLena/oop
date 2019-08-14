#pragma once
#include "vector.h"

template <typename T>
Vector<T>::Vector() {
	m_ptr = nullptr;
	this->m_size = 0;
}

template <typename T>
Vector<T>::Vector(size_t size) {
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	this->m_size = size;
}

template <typename T>
Vector<T>::Vector(size_t size, const T* arr) {
	this->m_size = size;
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);

	for (int i = 0; i < size; i++) {
		m_ptr.get()[i] = arr[i];
	}
}

template <typename T>
Vector<T>::Vector(const std::vector<T> & v) {
	size_t size = v.size();
	this->m_size = size;
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	for (int i = 0; i < size; i++) {
		m_ptr.get()[i] = v[i];
	}
}
template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) {
	size_t size = list.size();
	this->m_size = size;
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	int i = 0;
	for (auto el : list) {
		m_ptr.get()[i] = el;
		i++;
	}
}
template <typename T>
Vector<T>::Vector(const Vector<T>& another) {
	int size = another.get_size();
	this->m_size = size;
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	for (int i = 0; i < size; i++) {
		m_ptr.get()[i] = another.m_ptr.get()[i];
	}
}

template <typename T>
Vector<T>::Vector(Vector<T>&& another) {
	this->m_size = another.get_size();
	this->m_ptr = another.m_ptr;
}

template <typename T>
Vector<T>::~Vector() {};