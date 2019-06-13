#pragma 
#include "myArray.h"

template <typename T>
int compUp(const void* a, const void* b) {
	return (int)(*(T*)a - *(T*)b);
}

template <typename T>
int compDown(const void* a, const void* b) {
	return (int)(*(T*)b - *(T*)a);
}

//constructors
template <typename T>
Array<T>::Array(size_t length) {
	this->m_ptr = (T*)new T[length];
	if (this->m_ptr == nullptr) {
		std::cout << "bad allocation" << std::endl;
	}
	else {
		this->m_allocated = length;
		this->m_length = 0;
	}
}
template <typename T>
Array<T>::Array(const std::initializer_list<T>& list) {
	this->m_allocated = 0;
	this->m_length = 0;
	this->m_ptr = nullptr;
	if (this->reallocate(list.size()) == 0) {
		this->m_length = this->m_allocated;
		size_t i = 0;
		for (T element : list) {
			(*this)[i] = element;
			i++;
		}
	}
}

//copy
template <typename T>
Array<T>::Array(const Array<T>& another) {
	if (this->reallocate(another.capacity()) == 0) {
		this->m_length = another.size();
		for (size_t i = 0; i < this->m_length; i++) {
			(*this)[i] = another[i];
		}
	}
	else {
		std::cout << "bad allocation" << std::endl;
	}
}
template <typename T>
Array<T>::Array(Array<T>& another) {
	if (this->reallocate(another.capacity()) == 0) {
		this->m_length = another.size();
		for (size_t i = 0; i < this->m_length; i++) {
			(*this)[i] = another[i];
		}
	}
	else {
		std::cout << "bad allocation" << std::endl;
	}
}
template <typename T>
Array<T>* Array<T>::clone() {
	Array<T> *res = new Array<T>;
	*res = *this;
	return res;
}
//assignments
template <typename T>
Array<T>& Array<T>::operator = (Array<T>& another) {
	if (this->reallocate(another.capacity()) == 0) {
		this->m_length = another.size();
		for (size_t i = 0; i < this->m_length; i++) {
			(*this)[i] = another[i];
		}
	}
	else {
		std::cout << "bad allocation" << std::endl;
	}
	return *this;
}
template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& another) {
	if (this->reallocate(another.capacity()) == 0) {
		this->m_length = another.size();
		for (size_t i = 0; i < this->m_length; i++) {
			(*this)[i] = another[i];
		}
	}
	else {
		std::cout << "bad allocation" << std::endl;
	}
	return *this;
}
template <typename T>
Array<T>& Array<T>::operator = (const std::initializer_list<T>& list) {
	if (this->reallocate(list.size()) == 0) {
		int i = 0;
		for (T element : list) {
			(*this)[i] = element;
			i++;
		}
		this->m_length = this->m_allocated;
	}
	return *this;
}

//print
template <typename T>
void Array<T>::print() const {
	if (this->m_length == 0) {
		std::cout << "Empty array\n";
		return;
	}
	std::cout << "Array: ";
	//itterator
	for (size_t i = 0; i < this->m_length; i++) {
		std::cout << this->m_ptr[i] << " ";
	}
	std::cout << '\n';
}
template <typename T>
void Array<T>::print_len() const {
	std::cout << "Size: " << this->size() << std::endl;
}
template <typename T>
void Array<T>::print_capacity() const {
	std::cout << "Capacity: " << this->capacity() << std::endl;
}

//check
template <typename T>
bool Array<T>::is_empty() const {
	return this->m_length == 0;
}
template <typename T>
bool Array<T>::is_enough() const {
	return this->m_allocated > this->m_length;
}
template <typename T>
bool Array<T>::includes(T element) {
	if (this->find(element) == -1) {
		return false;
	}
	return true;
}

//getters
template <typename T>
size_t Array<T>::size() const {
	return this->m_length;
}
template <typename T>
size_t Array<T>::capacity() const {
	return this->m_allocated;
}

//element operations
template <typename T>
int Array<T>::append(T element) {
	int rc;
	if (this->m_allocated == this->m_length) {
		rc = this->reallocate(this->m_allocated + ALOCSTEP);
		if (rc == -1) { return rc; }
	}
	(*this)[this->m_length] = element;
	this->m_length += 1;
	return 0;
}
template <typename T>
int Array<T>::set(size_t index, T element) {
	if (index < 0 || index >= this->m_allocated) {
		return -1;
	}
	if (index >= this->m_length) {
		this->m_length = index + 1;
	}
	(*this)[index] = element;
	return 0;
}
template <typename T>
int Array<T>::remove(T element) {
	int index = this->find(element);
	if (index == -1) {
		return -1;
	}
	this->shift(index, -1);
	return 0;
}
template <typename T>
int Array<T>::find(T element) {
	for (size_t i = 0; i < this->m_length; i++) {
		if ((*this)[i] == element) {
			return i;
		}
	}
	return -1;
}
template <typename T>
T& Array<T>::operator [](size_t index) {
	return this->m_ptr[index];
}

//sorting
template <typename T>
void Array<T>::sortThisUp() {
	qsort(this->m_ptr, this->m_length, sizeof(T), compUp<T>);
}
template <typename T>
void Array<T>::sortThisDown() {
	qsort(this->m_ptr, this->m_length, sizeof(T), compDown<T>);
}
template <typename T>
Array<T> Array<T>::sortCopyUp() {
	Array<T> copy  = *this;
	copy.sortThisUp();
	return copy;
}
template <typename T>
Array<T> Array<T>::sortCopyDown() {
	Array<T> copy = *this;
	copy.sortThisDown();
	return copy;
}

template <typename T>
int Array<T>::reallocate(size_t size) {
	T* tmp = new T[size];
	if (tmp == nullptr) {
		std::cout << "bad allocation" << std::endl;
		return -1;
	}
	this->m_allocated = size;
	size_t length = this->m_allocated < this->m_length ? this->m_allocated : this->m_length;
	for (size_t i = 0; i < length; i++) {
		tmp[i] = (*this)[i];
	}
	delete[] this->m_ptr;
	this->m_ptr = tmp;
	return 0;
}
template <typename T>
void Array<T>::shift(size_t index, int number) {
	if (number < 0) {
		number = -number;
		for (size_t i = index; i < this->m_length - number - 1; i++) {
			this[i] = this[i + number];
		}
		this->m_length -= number;
	}
	else if (number > 0) {
		for (size_t i = this->m_length - 1; i > number; i--) {
			this[i] = this[i - number];
		}
	}	
}
template <typename T>
int Array<T>::fillRange(T start, T end, T step) {
	int count = (int)round((end - start) / (double)step);
	int rc = this->reallocate(count);
	if (rc == 0) {
		T el = start;
		for (int i = 0; i < count; i++) {
			(*this)[i] = el;
			el += step;
		}
		this->m_length = count;
	}
	return rc;
}