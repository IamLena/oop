#ifndef ITERATOR_IMP_H
#define ITERATOR_IMP_H

#include "iterator_2.h"
#include "exception.h"

template <class T>
BaseIterator<T>::BaseIterator(const std::shared_ptr<T>& address, size_t power)
{
    this->address = address;
    this->index = 0;
    this->size = power;
}

template <class T>
BaseIterator<T>::BaseIterator(const BaseIterator<T> &other)
{
    address = other.address;
    index = other.index;
    this->size = other.size;
}

template <class T>
bool BaseIterator<T>::check() const
{
    return !address.expired() && index >=0 && index < size;
}

template <class T>
BaseIterator<T>& BaseIterator<T>::operator ++()
{
    ++index;
    return *this;
}

template <class T>
BaseIterator<T>& BaseIterator<T>::operator --()
{
    --index;
    return *this;
}

template <class T>
BaseIterator<T> BaseIterator<T>::operator ++(int)
{
    BaseIterator tmp(*this);
    ++index;
    return tmp;
}

template <class T>
BaseIterator<T> BaseIterator<T>::operator --(int)
{
    BaseIterator tmp(*this);
    --index;
    return tmp;
}

template <typename Type>
bool operator == (const BaseIterator<Type>& it1, const BaseIterator<Type>& it2)
{
    return it1.actual_address() == it2.actual_address();
}

template <typename Type>
bool operator != (const BaseIterator<Type>& it1, const BaseIterator<Type>& it2)
{
    return it1.actual_address() != it2.actual_address();
}

template <typename T>
std::shared_ptr<T> BaseIterator<T>::actual_address() const
{
    if (address.lock() == 0 || !this->check())
        throw base_exception(__FILE__, typeid(*this).name(), __LINE__, "Iterator error!");
    T* deb = address.lock().get() + index;
    return deb;
}

#endif // ITERATOR_IMP_H
