#pragma once
#include "set.h"

//copy
template <typename T>
Set<T>::Set(const Set& another) {
	if (this->reallocate(another.capacity()) == 0) {
		this->m_length = another.m_length;
		for (size_t i = 0; i < this->m_length; i++) {
			(*this)[i] = another[i];
		}
	}
	else {
		std::cout << "bad allocation" << std::endl;
	}
}

template <typename T>
Set<T>* Set<T>::clone() const { 
	return new Set(*this); 
}

//print
template <typename T>
void Set<T>::print() const {
	if (this->m_length == 0) {
		std::cout << "Empty set\n";
		return;
	}
	std::cout << "Set: ";
	for (size_t i = 0; i < this->m_length; i++) {
		std::cout << this->m_ptr[i] << " ";
	}
	std::cout << '\n';
}

//append
template <typename T>
int Set<T>::append(T element) {
	int rc;
	if (!this->is_enough()) {
		rc = this->reallocate(this->m_length + ALOCSTEP);
		if (rc == -1) { return -1; }
	}
	if (!this->includes(element)) {
		this->m_ptr[this->m_length] = element;
		this->m_length += 1;
		return 0;
	}
	return 1;
}

//check
template <typename T>
bool Set<T>::operator == (const Set<T>& another_set) const {
	if (this->m_length != another_set.size()) {
		return false;
	}
	for (int i = 0; i < this->m_length; i++) {
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