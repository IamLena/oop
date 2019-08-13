#pragma once
#include "base.h"

base::BaseContainer::BaseContainer() { m_count = 0; }
base::BaseContainer::BaseContainer(size_t count) { m_count = count; }
base::BaseContainer::~BaseContainer() {}
bool base::BaseContainer::is_empty() const { return m_count == 0; }
size_t base::BaseContainer::get_size() const { return m_count; }

//----------------------------- Iterator ------------------------------------
template <typename T>
base::Iterator<T>::Iterator() {
	beg = nullptr;
	m_index = -1;
	m_size = 0;
}
template <typename T>
base::Iterator<T>::Iterator(int size, std::shared_ptr<T>& ptr) {
	beg = ptr;
	m_index = 0;
	m_size = size;
}
template <typename T>
base::Iterator<T>::Iterator(int size, T* ptr) {
	beg = std::make_shared<T>(ptr);
	m_index = 0;
	m_size = size;
}
template <typename T>
base::Iterator<T>::Iterator(const Iterator<T>& iter) { // how?
	beg = iter.beg;
	m_index = iter.m_index;
	m_size = iter.m_size;
}
template <typename T>
base::Iterator<T>& base::Iterator<T>::operator = (const Iterator<T>& iter) {
	beg = iter.beg();
	m_index = iter.m_index;
	m_size = iter.m_size;
}
template <typename T>
base::Iterator<T>::~Iterator() {
	beg.reset();
}

template <typename T>
base::Iterator<T>& base::Iterator<T>::operator ++ () {
	m_index ++;
	return *this;
}
template <typename T>
base::Iterator<T>& base::Iterator<T>::operator -- () {
	m_index--;
	return *this;
}
template <typename T>
base::Iterator<T> base::Iterator<T>::operator ++ (int i) {
	base::Iterator<T> ret = *this;
	m_index++;
	return ret;
}
template <typename T>
base::Iterator<T> base::Iterator<T>::operator -- (int i) {
	base::Iterator<T> ret = *this;
	m_index--;
	return ret;
}
template <typename T>
base::Iterator<T>& base::Iterator<T>::operator += (int i) {
	m_index += i;
	return *this;
}
template <typename T>
base::Iterator<T>& base::Iterator<T>::operator -= (int i) {
	m_index -= i;
	return *this;
}
template <typename T>
base::Iterator<T> base::Iterator<T>::operator + (int num) const {
	base::Iterator<T> ret = *this;
	ret.m_index += num; //?
	return ret;
}
template <typename T>
base::Iterator<T> base::Iterator<T>::operator - (int num) const {
	base::Iterator<T> ret = *this;
	ret.m_index -= num; //?
	return ret;
}

template <typename T>
bool base::Iterator<T>::operator == (const Iterator<T>& iter) const {
	return this.get_value() == iter.get_value();
}
template <typename T>
bool base::Iterator<T>::operator != (const Iterator<T>& iter) const {
	return this->get_value() != iter.get_value();
}
template <typename T>
bool base::Iterator<T>::operator < (const Iterator<T>& iter) const {
	return this->get_value() < iter.get_value();
}
template <typename T>
bool base::Iterator<T>::operator > (const Iterator<T>& iter) const {
	return this->get_value() > iter.get_value();
}
template <typename T>
bool base::Iterator<T>::operator >= (const Iterator<T>& iter) const {
	return this->get_value() >= iter.get_value();
}
template <typename T>
bool base::Iterator<T>::operator <= (const Iterator<T>& iter) const {
	return this->get_value() <= iter.get_value();
}
template <typename T>
T base::Iterator<T>::get_value() const {
	T* ptr = beg.lock().get();
	return ptr[m_index];
}

/*template <typename Type>
std::ostream& operator<<(std::ostream& os, const base::Iterator<Type>& iter)
{
	os << iter.get_value();
	return os;
}*/