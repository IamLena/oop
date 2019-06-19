#pragma once
#include "base_container.h"
#include "set_iterator_imp.h"

#include <memory>
template <typename T>
class Set : public base_container {
private:
	size_t m_allocated;
	std::shared_ptr<T> m_ptr;
public:
	//constructors
	Set();
	Set(size_t length);
	Set(const std::initializer_list<T> list);
	Set(T* arr, int length);
	//destructor
	~Set() {}

	//copy
	Set(const Set<T>& another);
	Set(Set<T>& another);
	std::shared_ptr<Set<T>> clone() const;
	//assignments
	Set<T>& operator = (Set<T>& another);
	Set<T>& operator = (const Set<T>& another);
	Set<T>& operator = (const std::initializer_list<T> list);

	//print
	friend std::ostream& operator<< (std::ostream& stream, const Set<T>& set) {
		//os << dt.mo << '/' << dt.da << '/' << dt.yr;
		size_t len = set.m_length;
		for (size_t i = 0; i < len; i++) {
			stream << set[i];
		}
		return stream;
	}

	//check
	bool is_empty() const;
	bool is_enough() const;
	bool includes(T& element) const;
	bool includes(ConstIterator<T>& iter) const;
	bool operator ==(const Set<T>& another_set) const;
	bool operator !=(const Set<T>& another_set) const;

	//getters
	size_t size() const;
	size_t capacity() const;

	//element operations
	Set<T>& append(T element);
	Set<T>& append(ConstIterator<T> iter);
	Set<T>& remove(T element);
	Set<T>& remove(ConstIterator<T> iter);
	int find(T& element) const;
	int find(ConstIterator<T>& iter);
	T& operator [](size_t index) const;

	Set<T>& reallocate(size_t size);
	Set<T>& shiftLeft(size_t index, int number);
	Set<T>& fillRange(T start, T end, T step = 1);

	//set operations
	Set<T> unionMethod(Set<T>& another_set) const;
	Set<T> operator + (Set<T>& another_set) const;

	Set<T> intersection(Set<T>& another_set) const;

	Set<T> substraction(Set<T>& another_set) const;
	Set<T> operator - (Set<T>& another_set) const;

	ConstIterator<T> inititalizeIterator() const;
};