#pragma once
#include <algorithm>

#define ALOCSTEP 5

int comp(const void* a, const void* b) {
	return (int)(*(int*)a - *(int*)b);
}

template <typename T>
class Array {
private:
	size_t m_allocated;
protected:
	size_t m_length;
	T* m_ptr;
public:
	Array() : m_allocated(0), m_length(0), m_ptr(nullptr) {}
	Array(size_t length) {
		if (m_ptr == nullptr) {
			std::cout << "bad allocation" << std::endl;
		}
		else {
			m_length = length;
			m_ptr = (T*)new T[length];
			m_allocated = length;
		}
	}
	Array(const std::initializer_list<T>& list) {
		if (this->allocate(list.size()) == 0) {
			int i = 0;
			for (T element : list) {
				m_ptr[i] = element;
				i++;
			}
			m_length = m_allocated;
		}
	}
	~Array() {
		delete[] m_ptr;
	}

	size_t size() const{
		return m_length;
	}
	size_t capacity() const {
		return m_allocated;
	}

	int allocate(size_t size) {
		if (m_allocated < size) {
			T* tmp = new T[size];
			if (tmp == nullptr) {
				std::cout << "bad allocation" << std::endl;
				return -1;
			}
			m_allocated = size;
			for (size_t i = 0; i < m_length; i++) {
				*(tmp + i) = *(m_ptr + i);
			}
			delete[] m_ptr;
			m_ptr = tmp;
		}
		return 0;
	}
	int append(T element) {
		int rc;
		if (m_allocated == m_length) {
			rc = this->allocate(m_allocated + ALOCSTEP);
			if (rc == -1) { return rc; }
		}
		m_ptr[m_length] = element;
		m_length += 1;
		return 0;
	}
	void fillZeros() {
		for (size_t i = 0; i < m_allocated; i++) {
			*(m_ptr + i) = 0;
		}
		m_length = m_allocated;
	}
	
	int fillRange(T start, T end, T step = 1) {
		int count = (int)round ((end - start) / (double)step);
		int rc = this->allocate(count);
		if (rc == 0) {
			T el = start;
			for (int i = 0; i < count; i++) {
				*(m_ptr + i) = el;
				el += step;
			}
			m_length = count;
		}
		return rc;
	}
	void print() const {
		if (m_length == 0) {
			std::cout << "the array is empty\n";
		}
		else {
			std::cout << "Array: ";
			for (size_t i = 0; i < m_length; i++) {
				std::cout << *(m_ptr + i) << " ";
			}
			std::cout << "\n";
		}
	}

	T operator [](size_t index) {
		return *(m_ptr + index);
	}

	void sortThis() {
		qsort(m_ptr, m_length, sizeof(m_ptr[0]), comp);
	}

	std::shared_ptr<Array<T>> copy() {
		std::cout << "copying" << std::endl;
		std::shared_ptr<Array<T>> tmp = std::shared_ptr<Array<T>>(new Array<T>);
		if (tmp->allocate(m_allocated) == 0) {
			tmp->m_length = m_length;
			for (size_t i = 0; i < tmp->m_length; i++) {
				*(tmp->m_ptr + i) = *(m_ptr + i);
			}
		}
		else {
			std::cout << "bad allocation" << std::endl;
		}
		
		return tmp;	
	}
	std::shared_ptr <Array<T>> sortCopy() {
		std::shared_ptr <Array<T>> tmp = this->copy();
		qsort(tmp->m_ptr, tmp->m_length, sizeof(tmp->m_ptr[0]), comp);
		return tmp;
	}
};