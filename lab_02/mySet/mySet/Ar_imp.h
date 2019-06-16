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
Array<T>::Array(const std::initializer_list<T>& list) {
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

//copy
template <typename T>
Array<T>::Array(const Array<T>& another) {
	this->reallocate(another.capacity());
	this->m_length = another.size();
	for (size_t i = 0; i < this->m_length; i++) {
		(*this)[i] = another[i];
	}
}
template <typename T>
Array<T>::Array(Array<T>& another) {
	this->reallocate(another.capacity());
	this->m_length = another.size();
	for (size_t i = 0; i < this->m_length; i++) {
		(*this)[i] = another[i];
	}
}
template <typename T>
std::shared_ptr<Array<T>> Array<T>::clone() const {
	return std::shared_ptr<Array<T>> (new Array(*this));
}
//assignments
template <typename T>
Array<T>& Array<T>::operator = (Array<T>& another) {
	this->reallocate(another.capacity());
	this->m_length = another.size();
	for (size_t i = 0; i < this->m_length; i++) {
		(*this)[i] = another[i];
	}
	return *this;
}
template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& another) {
	this->reallocate(another.capacity());
	this->m_length = another.size();
	for (size_t i = 0; i < this->m_length; i++) {
		(*this)[i] = another[i];
	}
	return *this;
}
template <typename T>
Array<T>& Array<T>::operator = (const std::initializer_list<T>& list) {
	this->reallocate(list.size());
	int i = 0;
	for (T element : list) {
		(*this)[i] = element;
		i++;
	}
	this->m_length = this->m_allocated;
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
	for (size_t i = 0; i < this->m_length; i++) {
		std::cout << this->m_ptr.get()[i] << " ";
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
bool Array<T>::includes(T element) const {
	if (this->find(element) == -1) {
		return false;
	}
	return true;
}
template <typename T>
bool Array<T>::includes(ConstIterator<T>& iter) const {
	if (this->find(iter) == -1) {
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
Array<T>& Array<T>::append(T element) {
	if (this->m_allocated == this->m_length) {
		this->reallocate(this->m_allocated + ALOCSTEP);
	}
	(*this)[this->m_length] = element;
	this->m_length += 1;
	return *this;
}
template<typename T>
Array<T>& Array<T>::append(ConstIterator<T>& iter) {
	if (this->m_allocated == this->m_length) {
		this->reallocate(this->m_allocated + ALOCSTEP);
	}
	(*this)[this->m_length] = *iter;
	this->m_length += 1;
	return *this;
}
template <typename T>
Array<T>& Array<T>::set(size_t index, T element) {
	if (index < 0 || index >= this->m_allocated) {
		throw size_exception(__FILE__, typeid(*this).name(), __LINE__, "Index out of memmory");
	}
	if (index >= this->m_length) {
		this->m_length = index + 1;
	}
	(*this)[index] = element;
	return *this;
}

template <typename T>
Array<T>& Array<T>::remove(T element) {
	int index = this->find(element);
	if (index != -1) {
		this->shiftLeft(index, 1);
	}
	return *this;
}
template <typename T>
Array<T>& remove(ConstIterator<T>& iter) {
	int index = this->find(*iter);
	if (index != -1) {
		this->shiftLeft(index, 1);
	}
	return *this;
}
template <typename T>
int Array<T>::find(T element) const{
	for (size_t i = 0; i < this->m_length; i++) {
		if ((*this)[i] == element) {
			return i;
		}
	}
	return -1;
}
template<typename T>
int Array<T>::find(ConstIterator<T>& iter) {
	for (size_t i = 0; i < this->m_length; i++) {
		if ((*this)[i] == *iter) {
			return i;
		}
	}
	return -1;
}
template <typename T>
T& Array<T>::operator [](size_t index) const {
	if (index < 0 || index >= this->capacity()) {
		throw size_exception(__FILE__, typeid(*this).name(), __LINE__, "Index out of range");
	}
	return this->m_ptr.get()[index];
}

//sorting
/*template <typename T>
void Array<T>::sortThisUp() {
	//std::sort(m_ptr, m_ptr + m_length);
	//std::sort(m_ptr, m_ptr + m_length, compUp<T>);
	//qsort(this->m_ptr, this->m_length, sizeof(T), compUp<T>);
}
template <typename T>
void Array<T>::sortThisDown() {
	qsort(this->m_ptr, this->m_length, sizeof(T), compDown<T>);
}
template <typename T>
Array<T> Array<T>::sortCopyUp() const {
	Array<T> copy  = *this;
	copy.sortThisUp();
	return copy;
}
template <typename T>
Array<T> Array<T>::sortCopyDown() const{
	Array<T> copy = *this;
	copy.sortThisDown();
	return copy;
}*/

template <typename T>
Array<T>& Array<T>::reallocate(size_t size) {
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
Array<T>& Array<T>::shiftLeft(size_t index, int number) {
	for (size_t i = index; i < this->m_length - number; i++) {
		(*this)[i] = (*this)[i + number];
	}
	this->m_length -= number;
	return *this;
}
template <typename T>
Array<T>& Array<T>::fillRange(T start, T end, T step) {
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

template<typename T>
ConstIterator<T> Array<T>::inititalizeIterator() const
{
	return ConstIterator<T>(this->m_ptr, this->m_length);
}