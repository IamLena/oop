#pragma once
#include "myArray.h"

int compUp(const void* a, const void* b) {
	return (int)(*(int*)a - *(int*)b);
}

int compDown(const void* a, const void* b) {
	return (int)(*(int*)b - *(int*)a);
}

template <typename T>
Array<T>::Array(size_t length) {
	this->m_ptr = (T*)new T[length];
	if (this->m_ptr == nullptr) {
		std::cout << "bad allocation" << std::endl;
	}
	else {
		this->m_length = length;
		this->m_allocated = length;
	}
}

template <typename T>
Array<T>::Array(const std::initializer_list<T>& list) {
	this->m_allocated = 0;
	if (this->reallocate(list.size()) == 0) {
		int i = 0;
		for (T element : list) {
			this->m_ptr[i] = element;
			i++;
		}
		this->m_length = this->m_allocated;
	}
}

template <typename T>
std::shared_ptr<Array<T>> Array<T>::copy() {
	std::shared_ptr<Array<T>> tmp = std::shared_ptr<Array<T>>(new Array<T>);
	if (tmp->reallocate(this->m_allocated) == 0) {
		tmp->m_length = this->m_length;
		for (size_t i = 0; i < tmp->m_length; i++) {
			*(tmp->m_ptr + i) = *(this->m_ptr + i);
		}
	}
	else {
		std::cout << "bad allocation" << std::endl;
	}

	return tmp;
}

template <typename T>
size_t Array<T>::size() const {
	return this->m_length;
}

template <typename T>
size_t Array<T>::capacity() const {
	return this->m_allocated;
}

template <typename T>
int Array<T>::reallocate(size_t size) {
	if (this->m_allocated < size) {
		T* tmp = new T[size];
		if (tmp == nullptr) {
			std::cout << "bad allocation" << std::endl;
			return -1;
		}
		this->m_allocated = size;
		for (size_t i = 0; i < this->m_length; i++) {
			*(tmp + i) = *(m_ptr + i);
		}
		delete[] m_ptr;
		this->m_ptr = tmp;
	}
	return 0;
}

template <typename T>
int Array<T>::append(T element) {
	int rc;
	if (this->m_allocated == this->m_length) {
		rc = this->reallocate(this->m_allocated + ALOCSTEP);
		if (rc == -1) { return rc; }
	}
	this->m_ptr[m_length] = element;
	this->m_length += 1;
	return 0;
}
template<typename T>
int Array<T>::fillRange(T start, T end, T step) {
	int count = (int)round((end - start) / (double)step);
	int rc = this->reallocate(count);
	if (rc == 0) {
		T el = start;
		for (int i = 0; i < count; i++) {
			*(this->m_ptr + i) = el;
			el += step;
		}
		this->m_length = count;
	}
	return rc;
}

template<typename T>
int Array<T>::fillRange(T start, T end) {
	int count = (int)round(end - start);
	int rc = this->allocate(count);
	if (rc == 0) {
		T el = start;
		for (int i = 0; i < count; i++) {
			*(this->m_ptr + i) = el;
			el++;
		}
		this->m_length = count;
	}
	return rc;
}

template <typename T>
void Array<T>::sortThisUp() {
	qsort(this->m_ptr, this->m_length, sizeof(T), compUp);
}

template <typename T>
void Array<T>::sortThisDown() {
	qsort(this->m_ptr, this->m_length, sizeof(T), compDown);
}

template <typename T>
std::shared_ptr <Array<T>> Array<T>::sortCopyUp() {
	std::shared_ptr <Array<T>> tmp = this->copy();
	qsort(tmp->m_ptr, tmp->m_length, sizeof(tmp->m_ptr[0]), compUp);
	return tmp;
}

template <typename T>
std::shared_ptr <Array<T>> Array<T>::sortCopyDown() {
	std::shared_ptr <Array<T>> tmp = this->copy();
	qsort(tmp->m_ptr, tmp->m_length, sizeof(tmp->m_ptr[0]), compDown);
	return tmp;
}

template <typename T>
void Array<T>::print() const{
	if (this->m_length == 0) {
		std::cout << "Empty array\n";
		return;
	}
	std::cout << "Array: ";
	for (size_t i = 0; i < this->m_length; i++) {
		std::cout << *(this->m_ptr + i) << " ";
	}
	std::cout << '\n';
}