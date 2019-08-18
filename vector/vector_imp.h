#pragma once
#include "vector.h"
#include "error.h"

template <typename T>
Vector<T>::Vector() {
	m_ptr = nullptr;
	this->m_size = 0;
}

template <typename T>
Vector<T>::Vector(size_t size) {
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	if (m_ptr.get() == nullptr) {
		throw error::MemmoryError();
	}
	T* run = m_ptr.get();
	for (int i = 0; i < size; i++) {
		run[i] = 0;
	}
	this->m_size = size;
}

template <typename T>
Vector<T>::Vector(size_t size, const T* arr) {
	this->m_size = size;
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	if (m_ptr.get() == nullptr) {
		throw error::MemmoryError();
	}
	for (size_t i = 0; i < size; i++) {
		m_ptr.get()[i] = arr[i];
	}
}

template <typename T>
Vector<T>::Vector(const std::vector<T> & v) {
	size_t size = v.size();
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	if (m_ptr.get() == nullptr) {
		throw error::MemmoryError();
	}
	this->m_size = size;
	for (size_t i = 0; i < size; i++) {
		m_ptr.get()[i] = v[i];
	}
}
template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) {
	size_t size = list.size();
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	if (m_ptr.get() == nullptr) {
		throw error::MemmoryError();
	}
	this->m_size = size;
	int i = 0;
	for (auto el : list) {
		m_ptr.get()[i] = el;
		i++;
	}
}
template <typename T>
Vector<T>::Vector(const Vector<T>& another) {
	int size = another.get_size();
	m_ptr = std::shared_ptr<T>((T*)malloc(size * sizeof(T)), free);
	if (m_ptr.get() == nullptr) {
		throw error::MemmoryError();
	}
	this->m_size = size;
	for (int i = 0; i < size; i++) {
		m_ptr.get()[i] = another.m_ptr.get()[i];
	}
}

template <typename T>
Vector<T>::Vector(Vector<T>&& another) {
	this->m_size = another.get_size();
	this->m_ptr = another.m_ptr;
	another.set_size(0);
	another.m_ptr = nullptr;
}

template <typename T>
Vector<T>::~Vector() {};

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& another) {
	if (this->get_size() != another.get_size()) {
		throw error::SizeDismatch();
	}
	for (int i = 0; i < get_size(); i++) {
		m_ptr.get()[i] = another.m_ptr.get()[i];
	}
	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator = (Vector<T>&& another) {
	m_size = another.m_size;
	m_ptr = another.m_ptr;
	another.m_ptr = nullptr;
	another.set_size(0);
	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator = (std::initializer_list<T> list) {
	if (this->get_size() != list.size()) {
		throw error::SizeDismatch();
	}

	this->m_size = list.size();
	int i = 0;
	for (auto el : list) {
		m_ptr.get()[i] = el;
		i++;
	}
	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator = (const std::vector<T> v) {
	if (this->get_size() != v.size()) {
		throw error::SizeDismatch();
	}

	int size = v.size();
	this->m_size = size;
	for (int i = 0; i < size; i++) {
		m_ptr.get()[i] = v[i];
	}
	return *this;
}

template <typename T>
base::Iterator<T> Vector<T>::begin() {
	base::Iterator<T> iter(this->m_ptr);
	return iter;
}
template <typename T>
base::Iterator<T> Vector<T>::end() {
	base::Iterator<T> iter(this->m_ptr, this->m_size);
	return iter;
}
template <typename T>
base::ConstIterator<T> Vector<T>::begin() const {
	base::ConstIterator<T> iter(this->m_ptr);
	return iter;
}
template <typename T>
base::ConstIterator<T> Vector<T>::end() const {
	base::ConstIterator<T> iter(this->m_ptr, this->m_size);
	return iter;
}

template <typename T>
Vector<T> Vector<T>::operator +(const Vector<T>& v) const {
	Vector<T> result(v.get_size());
	auto v_iter = v.begin();
	auto this_iter = this->begin();
	for (auto r = result.begin(); r != result.end(); r++) {
		*(r.get_ptr()) = v_iter.get_value() + this_iter.get_value();
		this_iter++;
		v_iter++;
	}
	return result;
}
template <typename T>
Vector<T>& Vector<T>::add(const Vector<T>& v) {
	auto this_iter = this->begin();
	for (auto r = v.begin(); r != v.end(); r++) {
		*(this_iter.get_ptr()) += r.get_value();
		this_iter++;
	}
	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator += (const Vector<T>& v) {
	auto this_iter = this->begin();
	for (auto r = v.begin(); r != v.end(); r++) {
		*(this_iter.get_ptr()) += r.get_value();
		this_iter++;
	}
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator - (const Vector<T>& v) const {
	Vector<T> result(v.get_size());
	auto v_iter = v.begin();
	auto this_iter = this->begin();
	for (auto r = result.begin(); r != result.end(); r++) {
		*(r.get_ptr()) = this_iter.get_value() - v_iter.get_value();
		this_iter++;
		v_iter++;
	}
	return result;
}
template <typename T>
Vector<T>& Vector<T>::sub(const Vector<T>& v) {
	auto this_iter = this->begin();
	for (auto r = v.begin(); r != v.end(); r++) {
		*(this_iter.get_ptr()) -= r.get_value();
		this_iter++;
	}
	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator -= (const Vector<T>& v) {
	auto this_iter = this->begin();
	for (auto r = v.begin(); r != v.end(); r++) {
		*(this_iter.get_ptr()) -= r.get_value();
		this_iter++;
	}
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator * (T k) const {
	Vector<T> result(this->get_size());
	auto this_iter = this->begin();
	for (auto r = result.begin(); r != result.end(); r++) {
		*(r.get_ptr()) = this_iter.get_value() * k;
		this_iter++;
	}
	return result;
}
template <typename T>
Vector<T>& Vector<T>::operator *= (T k) {
	for (auto r = this->begin(); r != this->end(); r++) {
		*(r.get_ptr()) *= k;
	}
	return *this;
}
template <typename T>
Vector<T> Vector<T>::operator / (T k) const {
	Vector<T> result(this->get_size());
	auto this_iter = this->begin();
	for (auto r = result.begin(); r != result.end(); r++) {
		*(r.get_ptr()) = this_iter.get_value() / k;
		this_iter++;
	}
	return result;
}
template <typename T>
Vector<T>& Vector<T>::operator /= (T k) {
	for (auto r = this->begin(); r != this->end(); r++) {
		*(r.get_ptr()) /= k;
	}
	return *this;
}

template <typename T>
T Vector<T>::scalar_product(const Vector<T>& v) const {
	T result = 0; //how?
	auto v_iter = v.begin();
	for (auto r = this->begin(); r != this->end(); r++) {
		result += (r.get_value() * v_iter.get_value());
		v_iter++;
	}
	return result;
}

