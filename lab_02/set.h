#pragma once
#include "myArray_imp.h"

template <typename T>
class Set : public Array<T>
{
public:
	Set() : Array<T>() {};
	Set(size_t length) : Array<T>(length) {};
	Set(const std::initializer_list<T>& list) : Array<T>(list) {};

	void print() const override;
	int append(T element);

	std::shared_ptr <Set<T>> sortCopyUp();
	std::shared_ptr <Set<T>> sortCopyDown();
	std::shared_ptr<Set<T>> copy();
};