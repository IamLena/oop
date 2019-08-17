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

	Vector<T>& operator = (const Vector<T>& another);
	Vector<T>& operator = (Vector<T>&& another);
	Vector<T>& operator = (std::initializer_list<T> list);
	Vector<T>& operator = (const std::vector<T> v);

	~Vector();

	base::Iterator<T> begin();
	base::Iterator<T> end();
	base::Iterator<T> begin() const;
	base::Iterator<T> end() const;

	T length() {
		T len = 0;
		return len;
	}

	T scalar_product(const Vector<T>& v) const;
	/*Vector<T> vector_product(const Vector<T>& v) const;
	bool is_coleniar(const Vector<T>& v) const;
	
	int angle(const Vector<T>& v) const;
	[]
	*/
	bool is_normal(const Vector<T>& v) const {
		return this->set_size(v) == 0;
	}

	bool operator == (const Vector<T>& v) {
		if (this->get_size() != v.get_size()) {
			return false;
		}
		auto iter = this->begin();
		for (auto el = v.begin(); el != v.end(); el++) {
			if (el.get_value() != iter.get_value()) {
				return false;
				iter++;
			}
		}
		return true;
	}

	bool operator != (const Vector<T>& v) {
		return !(*this == v);
	}

	//same and zero size exception
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
};