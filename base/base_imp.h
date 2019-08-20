#pragma once
#include "base.h"
#include "error.h"

base::BaseContainer::BaseContainer() { m_size = 0; }
base::BaseContainer::BaseContainer(size_t count) { m_size = count; }
base::BaseContainer::~BaseContainer() {}
bool base::BaseContainer::is_empty() const { return m_size == 0; }
size_t base::BaseContainer::get_size() const { return m_size; }
void base::BaseContainer::set_size(int size) { m_size = size; }

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
	if (m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	m_index ++;
	return *this;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator -- () {
	if (m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	m_index--;
	return *this;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator ++ (int i) {
	if (m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	base::BaseIterator<T> ret(*this);
	m_index++;
	return ret;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator -- (int i) {
	if (m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	base::BaseIterator<T> ret(*this);
	m_index--;
	return ret;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator += (int i) {
	if (m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	m_index += i;
	return *this;
}
template <typename T>
base::BaseIterator<T>& base::BaseIterator<T>::operator -= (int i) {
	if (m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	m_index -= i;
	return *this;
}
template <typename T>
base::BaseIterator<T> base::BaseIterator<T>::operator + (int num) const {
	if (m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	base::BaseIterator<T> ret(*this);
	ret.m_index += num; //?
	return ret;
}
template <typename T>
base::BaseIterator<T> base::BaseIterator<T>::operator - (int num) const {
	if (m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	base::BaseIterator<T> ret (*this);
	ret.m_index -= num; //?
	return ret;
}

template <typename T>
bool base::BaseIterator<T>::operator == (const BaseIterator<T>& iter) const {
	return this.m_ptr  == iter.m_ptr && this.m_index == iter.m_index;
}
template <typename T>
bool base::BaseIterator<T>::operator != (const BaseIterator<T>& iter) const {
	return this->m_ptr.lock().get() != iter.m_ptr.lock().get() || this->m_index != iter.m_index;
}

//--------------------------------Iterator---------------------------------------
template <typename T>
base::Iterator<T>::Iterator(std::shared_ptr<T> ptr, size_t index) : base::BaseIterator<T>(ptr, index) {}

template <typename T>
base::Iterator<T>::Iterator(const Iterator<T>& iter) : base::BaseIterator<T>(iter.m_ptr.lock(), iter.m_index) {}


template <typename T>
T* base::Iterator<T>::get_ptr() {
	if (this->m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	return this->m_ptr.lock().get() + this->m_index;
}

template <typename T>
const T* base::Iterator<T>::get_ptr() const {
	if (this->m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	return this->m_ptr.lock().get() + this->m_index;
}

template <typename T>
T base::Iterator<T>::get_value() {
	if (this->m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	return *(this->get_ptr());
}

template <typename T>
const T base::Iterator<T>::get_value() const{
	if (this->m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	return *(this->get_ptr());
}

//---------------------------ConstIterator-------------------------------------------
template <typename T>
base::ConstIterator<T>::ConstIterator(std::shared_ptr<T> ptr, size_t index) : base::BaseIterator<T>(ptr, index) {}

template <typename T>
base::ConstIterator<T>::ConstIterator(const ConstIterator<T>& iter) : base::BaseIterator<T>(iter.m_ptr.lock(), iter.m_index) {}

template <typename T>
const T* base::ConstIterator<T>::get_ptr() const {
	if (this->m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	return this->m_ptr.lock().get() + this->m_index;
}

template <typename T>
const T base::ConstIterator<T>::get_value() const {
	if (this->m_ptr.expired()) {
		throw error::ExpiredWeakPtr();
	}
	return *(this->get_ptr());
}