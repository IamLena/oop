#pragma once
#include "base_imp.h"
#include <iostream>
#include <initializer_list>
#include <vector>
#include <memory>

template <typename  T>
class Vector : public base::BaseContainer{
private:
	std::shared_ptr<T> m_ptr;
public:
	Vector();
	explicit Vector(size_t size);
	explicit Vector(size_t size, const T* arr);
	Vector(const std::vector<T> &v);
	Vector(std::initializer_list<T> list);
	Vector(const Vector<T>& another);
	Vector(Vector<T>&& another);

	/*Vector<T>& operator = (const Vector<T>& another);
	Vector<T>& operator = (Vector<T>& another);
	Vector<T>& operator = (std::initializer_list<T> list);
	Vector<T>& operator = (const std::vector<T> v);*/

	~Vector();

	/*base::Iterator<T> begin();
	base::Iterator<T> end();
	base::ConstIterator<T> begin() const;
	base::ConstIterator<T> end() const;*/

	/*
	scalar_product
	vector_product
	coleniar
	normal
	angle
	add + +=
	minus - -=
	koef * *=
	*/
};