#pragma once
#include <iostream>
#include <algorithm> //for list
#include "set_iterator_imp.h"
#define ALOCSTEP 5

template <typename T>
class Array {
private:
	size_t m_allocated;
protected:
	size_t m_length;
	std::shared_ptr<T> m_ptr;
public:
	//constructors
	Array() : m_allocated(0), m_length(0), m_ptr(nullptr) {}
	Array(size_t length);
	Array(const std::initializer_list<T>& list);
	//destructor
	~Array() {}

	//copy
	Array(const Array<T>& another);
	Array(Array<T>& another);
	std::shared_ptr<Array<T>> clone() const;
	//assignments
	Array<T>& operator = (Array<T>& another);
	Array<T>& operator = (const Array<T>& another);
	Array<T>& operator = (const std::initializer_list<T>& list);

	//print
	virtual void print() const;
	void print_len() const;
	void print_capacity() const;
	
	//check
	bool is_empty() const;
	bool is_enough() const;
	bool includes(T element) const;
	bool includes(ConstIterator<T>& iter) const;

	//getters
	size_t size() const;
	size_t capacity() const;

	//element operations
	Array<T>& append(T element);
	Array<T>& append(ConstIterator<T>& iter);
	Array<T>& set(size_t index, T element);
	Array<T>& remove(T element);
	Array<T>& remove(ConstIterator<T>& iter);
	int find(T element) const;
	int find(ConstIterator<T>& iter);
	T& operator [](size_t index) const;
	
	//sorting
	/*void sortThisUp();
	void sortThisDown();
	Array<T> sortCopyUp() const;
	Array<T> sortCopyDown() const;*/

	Array<T>& reallocate(size_t size);
	Array<T>& shiftLeft(size_t index, int number);
	Array<T>& fillRange(T start, T end, T step = 1);

	ConstIterator<T> inititalizeIterator() const;
};