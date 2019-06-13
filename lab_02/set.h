#pragma once
#include "myArray_imp.h"

template <typename T>
class Set : public Array<T>
{
public:
	Set() : Array<T>() {};
	Set(size_t length) : Array<T>(length) {};
	Set(const std::initializer_list<T>& list) : Array<T>(list) {};
	Set(const Set& another);
	Set<T>* clone() const { return new Set(*this); }
	void print() const override;
	int append(T element);

	std::shared_ptr <Set<T>> sortCopyUp();
	std::shared_ptr <Set<T>> sortCopyDown();
	std::shared_ptr<Set<T>> copy();

	bool operator ==(const Set<T>& another_set) const;
	bool operator !=(const Set<T>& another_set) const;

	Set<T>& unionMethod(Set<T>& another_set);
	Set<T>& operator + (Set<T>& another_set);

	Set<T> intersection(Set<T>& another_set);
};