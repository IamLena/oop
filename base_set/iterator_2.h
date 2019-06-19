#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>

template <typename T>
class BaseIterator
{
protected:
	std::weak_ptr<T> address;
	size_t size;
	size_t index;

	T* actual_address() const;
public:
	BaseIterator() {};
	BaseIterator(const std::shared_ptr<T>& address, size_t size);
    BaseIterator(const BaseIterator<T> &other);

    bool check() const;

    BaseIterator& operator ++();
    BaseIterator& operator --();
    BaseIterator operator ++(int);
    BaseIterator operator --(int);

    template <typename Type>
    friend bool operator == (const BaseIterator<Type> &it1, const BaseIterator<Type> &it2);

    template <typename Type>
    friend bool operator != (const BaseIterator<Type> &it1, const BaseIterator<Type> &it2);
};

#endif // ITERATOR_H
