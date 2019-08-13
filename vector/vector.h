#pragma once
#include "base_imp.h"

template <typename  T>
class Vector : public base::BaseContainer{
private:
	std::shared_ptr<T> ptr;
public:
	Vector();
	explicit Vector(size_t size);
	Vector(std::initializer_list<T> list);

	/*Vector(const Vector<T>& another);
	Vector<T>& operator = (const Vector<T>& another);
	Vector(Vector<T>&& another);
	Vector<T>& operator = (Vector<T>& another);*/

	base::Iterator<T> begin();
	base::Iterator<T> end();

	~Vector();
};