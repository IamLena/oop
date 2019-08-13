#pragma once
#include "base.h"

base::BaseContainer::BaseContainer() { m_count = 0; }
base::BaseContainer::BaseContainer(size_t count) { m_count = count; }
base::BaseContainer::~BaseContainer() {}
bool base::BaseContainer::is_empty() const { return m_count == 0; }
size_t base::BaseContainer::get_size() const { return m_count; }
void base::BaseContainer::set_size(int size) { m_count = size; }

//----------------------------- BaseIterator ------------------------------------
template <typename T>
base::BaseIterator<T>::BaseIterator(std::shared_ptr<T> ptr, size_t index) {
	m_ptr = ptr;
	m_index = index;
}

template <typename T>
base::BaseIterator<T>::BaseIterator(const BaseIterator<T>& iter) { // how?
	m_ptr = iter.m_ptr.lock();
	m_index = iter.m_index;
}

template <typename T>
base::BaseIterator<T>::~BaseIterator() {
	m_ptr.reset();
}

template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator = (const BaseIterator<T>& iter) {
	m_ptr = iter.m_ptr().lock();
	m_index = iter.m_index;
}

template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator ++ () {
	m_index ++;
	return *this;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator -- () {
	m_index--;
	return *this;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator ++ (int i) {
	base::BaseIterator<T> ret(*this);
	m_index++;
	return ret;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator -- (int i) {
	base::BaseIterator<T> ret(*this);
	m_index--;
	return ret;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator += (int i) {
	m_index += i;
	return *this;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator -= (int i) {
	m_index -= i;
	return *this;
}
template <typename T>
base::BaseIterator<T> base::BaseIterator<T>::operator + (int num) const {
	base::BaseIterator<T> ret(*this);
	ret.m_index += num; //?
	return ret;
}
template <typename T>
base::BaseIterator<T> base::BaseIterator<T>::operator - (int num) const {
	base::BaseIterator<T> ret (*this);
	ret.m_index -= num; //?
	return ret;
}

/*template <typename T>
bool base::BaseIterator<T>::operator == (const BaseIterator<T>& iter) const {
	return this.get_value() == iter.get_value();
}
template <typename T>
bool base::BaseIterator<T>::operator != (const BaseIterator<T>& iter) const {
	return this->get_value() != iter.get_value();
}
template <typename T>
bool base::BaseIterator<T>::operator < (const BaseIterator<T>& iter) const {
	return this->get_value() < iter.get_value();
}
template <typename T>
bool base::BaseIterator<T>::operator > (const BaseIterator<T>& iter) const {
	return this->get_value() > iter.get_value();
}
template <typename T>
bool base::BaseIterator<T>::operator >= (const BaseIterator<T>& iter) const {
	return this->get_value() >= iter.get_value();
}
template <typename T>
bool base::BaseIterator<T>::operator <= (const BaseIterator<T>& iter) const {
	return this->get_value() <= iter.get_value();
}*/

//--------------------------------Iterator---------------------------------------
template <typename T>
base::Iterator<T>::Iterator(std::shared_ptr<T> ptr, size_t index) : base::BaseIterator<T>(ptr, index) {};

template <typename T>
base::Iterator<T>::Iterator(const Iterator<T>& iter) : base::BaseIterator<T>(iter.m_ptr, iter.m_index) {};

template <typename T>
base::Iterator<T>::~Iterator() {
	this->m_ptr.reset();
}

template <typename T>
T* base::Iterator<T>::get_ptr() {
	return this->m_ptr.get() + this->m_index;
}

template <typename T>
const T* base::Iterator<T>::get_ptr() const {
	return this->m_ptr.lock().get() + this->m_index;
}

template <typename T>
T base::Iterator<T>::get_value() {
	return *(this->get_ptr());
}

template <typename T>
const T base::Iterator<T>::get_value() const{
	return *(this->get_ptr());
}

//---------------------------ConstIterator-------------------------------------------
template <typename T>
base::ConstIterator<T>::ConstIterator(std::shared_ptr<T> ptr, size_t index) : base::BaseIterator<T>(ptr, index) {};

template <typename T>
base::ConstIterator<T>::ConstIterator(const ConstIterator<T>& iter) : base::BaseIterator<T>(iter.m_ptr, iter.m_index) {};

template <typename T>
base::ConstIterator<T>::~ConstIterator() {
	this->m_ptr.reset();
}

template <typename T>
const T* base::ConstIterator<T>::get_ptr() const {
	return this->m_ptr.lock().get() + this->m_index;
}

template <typename T>
const T base::ConstIterator<T>::get_value() const {
	return *(this->get_ptr());
}