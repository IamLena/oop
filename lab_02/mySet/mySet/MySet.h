#pragma once
#include "base_container.h"
#include "set_iterator_imp.h"

#include <memory>
template <typename T>
class Set : public base_container {
private:
	size_t m_allocated;
	std::shared_ptr<std::shared_ptr<T>[]> m_ptr;
public:
	//constructors
	Set();
	Set(T* arr, int length);
	Set(const std::initializer_list<T> list);
	explicit Set(const Set<T>& another);
	Set(Set<T>&& other);
	//destructor
	~Set() {}

	Set<T> clone() const;

	//assignments
	Set<T>& operator = (const Set<T>& another);
	Set<T>& operator = (Set<T>&& other);
	Set<T>& operator = (const std::initializer_list<T> list);

	//print
	template <typename U>
	friend std::ostream& operator<< (std::ostream& stream, const Set<U>& set);

	//check
	bool in(const T& element) const;
	bool in(const ConstIterator<T>& iter) const;
	bool operator < (const T& element) const;
	bool operator < (const ConstIterator<T>& iter) const;
	
	bool is_equal(const Set<T>& another_set) const;
	bool operator ==(const Set<T>& another_set) const;
	bool is_not_equal(const Set<T>& another_set) const;
	bool operator !=(const Set<T>& another_set) const;

	//getters
	size_t capacity() const;

	//element operations
	Set<T>& append(const T& element);
	Set<T> operator + (const T& element) const;
	Set<T>& operator += (const T& element);
	Set<T>& append(const ConstIterator<T>& iter);
	Set<T> operator + (const ConstIterator<T>& iter) const;
	Set<T>& operator += (const ConstIterator<T>& iter);

	Set<T>& remove(const T& element);
	Set<T> operator - (const T& element) const;
	Set<T>& operator -= (const T& element);
	Set<T>& remove(const ConstIterator<T>& iter);
	Set<T> operator - (const ConstIterator<T>& iter) const;
	Set<T>& operator -= (const ConstIterator<T>& iter);

	Set<T>& fillRange(T start, T end, T step = 1);

	//set operations
	Set<T> unionMethod(const Set<T>& another_set) const;
	Set<T> operator + (const Set<T>& another_set) const;
	Set<T>& operator += (const Set<T>& another_set);

	Set<T> intersection(const Set<T>& another_set) const;
	Set<T> operator & (const Set<T>& another_set) const;
	Set<T>& operator &= (const Set<T>& another_set);

	Set<T> substraction(const Set<T>& another_set) const;
	Set<T> operator - (const Set<T>& another_set) const;
	Set<T>& operator -= (const Set<T>& another_set);

	Set<T> simmetricSub(const Set<T>& another_set) const;
	Set<T> operator ^ (const Set<T>& another_set) const;
	Set<T>& operator ^= (const Set<T>& another_set);

	ConstIterator<T> inititalizeIterator() const;
private:
	bool is_enough() const;
	int find(const T& element) const;
	int find(const ConstIterator<T>& iter);
	Set<T>& reallocate(size_t size);
	Set<T>& shiftLeft(size_t index, int number);
	std::shared_ptr<T> operator [](size_t index) const;
	std::shared_ptr<std::shared_ptr<T>[]> get_ptr() const;
};