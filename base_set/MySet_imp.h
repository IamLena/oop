#pragma once
#include "MySet.h"
#include "exception.h"
#include <iostream>

#define ALOCSTEP 5

//constructors
template <typename T>
Set<T>::Set() {
	m_length = 0;
	m_allocated = 0;
	m_ptr = nullptr;
}

template <typename T>
Set<T>::Set(size_t length) {
	try {
		this->m_ptr = std::shared_ptr<T>(new T[length]);
		this->m_allocated = length;
		this->m_length = 0;
	}
	catch (std::bad_alloc)
	{
		throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__, "Memory error!");
	}
}

template <typename T>
Set<T>::Set(const std::initializer_list<T> list) {
	this->m_allocated = 0;
	this->m_length = 0;
	this->m_ptr = nullptr;
	this->reallocate(list.size());
	this->m_length = this->m_allocated;
	size_t i = 0;
	for (T element : list) {
		(*this)[i] = element;
		i++;
	}
}

template <typename T>
Set<T>::Set(T* arr, int length) {
	this->m_allocated = length;
	this->m_length = length;
	this->m_ptr = arr;
}

//copy
template <typename T>
Set<T>::Set(const Set<T>& another) {
	this->reallocate(another.capacity());
	this->m_length = another.size();
	for (size_t i = 0; i < this->m_length; i++) {
		(*this)[i] = another[i];
	}
}

template <typename T>
Set<T>::Set(Set<T>& another) {
	this->reallocate(another.capacity());
	this->m_length = another.size();
	for (size_t i = 0; i < this->m_length; i++) {
		(*this)[i] = another[i];
	}
}

template <typename T>
std::shared_ptr<Set<T>> Set<T>::clone() const {
	return std::shared_ptr<Set<T>>(new Set(*this));
}

//assignments
template <typename T>
Set<T>& Set<T>::operator = (Set<T>& another) {
	this->reallocate(another.capacity());
	this->m_length = another.size();
	for (size_t i = 0; i < this->m_length; i++) {
		(*this)[i] = another[i];
	}
	return *this;
}

template <typename T>
Set<T>& Set<T>::operator = (const Set<T>& another) {
	this->reallocate(another.capacity());
	this->m_length = another.size();
	for (size_t i = 0; i < this->m_length; i++) {
		(*this)[i] = another[i];
	}
	return *this;
}

template <typename T>
Set<T>& Set<T>::operator = (const std::initializer_list<T> list) {
	this->reallocate(list.size());
	int i = 0;
	for (T element : list) {
		(*this)[i] = element;
		i++;
	}
	this->m_length = this->m_allocated;
	return *this;
}

//check
template <typename T>
bool Set<T>::is_enough() const {
	return m_allocated > m_length;
}

template <typename T>
bool Set<T>::includes(T& element) const {
	if (this->find(element) == -1) {
		return false;
	}
	return true;
}

template <typename T>
bool Set<T>::includes(ConstIterator<T>& iter) const {
	if (this->find(iter) == -1) {
		return false;
	}
	return true;
}

template <typename T>
bool Set<T>::operator == (const Set<T>& another_set) const {
	if (this->m_length != another_set.size()) {
		return false;
	}
	for (size_t i = 0; i < this->m_length; i++) {
		T el = (*this)[i];
		if (!another_set.includes(el)) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool Set<T>::operator !=(const Set<T>& another_set) const {
	return !(*this == another_set);
}

//getters
template <typename T>
size_t Set<T>::capacity() const {
	return m_allocated;
}

//element operations
template <typename T>
Set<T>& Set<T>::append(T element) {
	if (!this->is_enough()) {
		this->reallocate(this->m_length + ALOCSTEP);
	}
	if (!this->includes(element)) {
		(*this)[this->m_length] = element;
		this->m_length += 1;
	}
	return *this;
}

template <typename T>
Set<T>& Set<T>::append(ConstIterator<T> iter) {
	if (!this->is_enough()) {
		this->reallocate(this->m_length + ALOCSTEP);
	}
	if (!this->includes(iter)) {
		(*this)[this->m_length] = *iter;
		this->m_length += 1;
	}
	return *this;
}

template <typename T>
Set<T>& Set<T>::remove(T element) {
	int index = this->find(element);
	if (index != -1) {
		this->shiftLeft(index, 1);
	}
	return *this;
}

template <typename T>
Set<T>& Set<T>::remove(ConstIterator<T> iter) {
	int index = this->find(*iter);
	if (index != -1) {
		this->shiftLeft(index, 1);
	}
	return *this;
}

template <typename T>
int Set<T>::find(T& element) const {
	for (size_t i = 0; i < this->m_length; i++) {
		if ((*this)[i] == element) {
			return i;
		}
	}
	return -1;
}

template <typename T>
int Set<T>::find(ConstIterator<T>& iter) {
	for (size_t i = 0; i < this->m_length; i++) {
		if ((*this)[i] == *iter) {
			return i;
		}
	}
	return -1;
}

template <typename T>
T& Set<T>::operator [](size_t index) const {
	if (index < 0 || index >= this->capacity()) {
		throw size_exception(__FILE__, typeid(*this).name(), __LINE__, "Index out of range");
	}
	return this->m_ptr.get()[index];
}

template <typename T>
Set<T>& Set<T>::reallocate(size_t size) {
	try {
		std::shared_ptr<T> tmp = std::shared_ptr<T>(new T[size]);
		this->m_allocated = size;
		size_t length = this->m_allocated < this->m_length ? this->m_allocated : this->m_length;
		for (size_t i = 0; i < length; i++) {
			tmp.get()[i] = (*this)[i];
		}
		this->m_ptr.reset();
		this->m_ptr = tmp;
		return *this;
	}
	catch (std::bad_alloc)
	{
		throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__, "Memory error!");
	}
}

template <typename T>
Set<T>& Set<T>::shiftLeft(size_t index, int number) {
	for (size_t i = index; i < this->m_length - number; i++) {
		(*this)[i] = (*this)[i + number];
	}
	this->m_length -= number;
	return *this;
}

template <typename T>
Set<T>& Set<T>::fillRange(T start, T end, T step) {
	int count = (int)round((end - start) / (double)step);
	this->reallocate(count);
	T el = start;
	for (int i = 0; i < count; i++) {
		(*this)[i] = el;
		el += step;
	}
	this->m_length = count;
	return *this;
}

//set operations
template <typename T>
Set<T> Set<T>::unionMethod(Set<T>& another_set) const {
	Set<T> copy = *this;
	for (size_t i = 0; i < another_set.size(); i++) {
		copy.append(another_set[i]);
	}
	return copy;
}

template <typename T>
Set<T> Set<T>::operator + (Set<T>& another_set) const {
	return this->unionMethod(another_set);
}

template <typename T>
Set<T> Set<T>::intersection(Set<T>& another_set) const {
	Set<T> copy = *this;
	for (size_t i = 0; i < copy.size(); i++) {
		T el = copy[i];
		if (!another_set.includes(el)) {
			copy.remove(el);
			i--;
		}
	}
	return copy;
}

template <typename T>
Set<T> Set<T>::substraction(Set<T>& another_set) const {
	Set<T> copy = *this;
	for (size_t i = 0; i < copy.size(); i++) {
		T el = copy[i];
		if (another_set.includes(el)) {
			copy.remove(el);
			i--;
		}
	}
	return copy;
}

template <typename T>
Set<T> Set<T>::operator - (Set<T>& another_set) const {
	return this->substraction(another_set);
}

template <typename T>
ConstIterator<T> Set<T>::inititalizeIterator() const {
	return ConstIterator<T>(this->m_ptr, this->m_length);
}
