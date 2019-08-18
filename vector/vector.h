#pragma once
#include "base_imp.h"
#include <iostream>
#include <initializer_list>
#include <vector>
#include <memory>
#include <cmath>

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

	Vector<T>& operator = (const Vector<T>& another);
	Vector<T>& operator = (Vector<T>&& another);
	Vector<T>& operator = (std::initializer_list<T> list);
	Vector<T>& operator = (const std::vector<T> v);

	~Vector();

	base::Iterator<T> begin();
	base::Iterator<T> end();
	base::ConstIterator<T> begin() const;
	base::ConstIterator<T> end() const;

	T length() const{
		T len = 0;
		for (size_t i = 0; i < this->get_size(); i++) {
			len += this->m_ptr.get()[i] * this->m_ptr.get()[i];
		}
		return sqrt(len);
	}

	Vector<T> vector_product(const Vector<T>& v) const;
	T scalar_product(const Vector<T>& v) const;
	T operator[] (size_t i);
	const T operator[] (size_t i) const;
	Vector<T>& normalize();
	Vector<T> norm() const;
	bool is_coleniar(const Vector<T>& v) const;
	T angle(const Vector<T>& v) const;
	bool is_normal(const Vector<T>& v) const;
	bool operator == (const Vector<T>& v);
	bool operator != (const Vector<T>& v);

	Vector<T> operator +(const Vector<T>& v) const;
	Vector<T>& add (const Vector<T>& v);
	Vector<T>& operator += (const Vector<T> & v);

	Vector<T> operator -(const Vector<T>& v) const;
	Vector<T>& sub(const Vector<T>& v);
	Vector<T>& operator -= (const Vector<T> & v);

	Vector<T> operator * (T k) const;
	Vector<T>& operator *= (T k);
	Vector<T> operator / (T k) const;
	Vector<T>& operator /= (T k);

	friend std::ostream& operator << (std::ostream& out, const Vector<T> v) {
		for (auto el = v.begin(); el != v.end(); el++) {
			out << el.get_value() << ", ";
		}
		out << "\n";
		return out;
	}
};