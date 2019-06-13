#pragma once
#include <algorithm>

#define ALOCSTEP 5

template <typename T>
class Array {
private:
	size_t m_allocated;
protected:
	size_t m_length;
	T* m_ptr;
public:
	Array() : m_allocated(0), m_length(0), m_ptr(nullptr) {}
	Array(size_t length);
	Array(const std::initializer_list<T>& list);
	~Array() { delete[] m_ptr;}

	Array<T>& operator = (Array<T> &another);
	Array<T>& operator = (const Array<T> &another);
	Array<T>& operator = (const std::initializer_list<T>& list);

	virtual void print() const;
	void print_len() const;
	void print_capacity() const;
	
	bool is_empty() const;
	bool is_enough() const;
	size_t size() const;
	size_t capacity() const;

	int reallocate(size_t size);
	void shift(size_t index, int number);
	int append(T element);
	int remove(T element);
	int find(T element);
	bool includes(T element);

	int fillRange(T start, T end, T step = 1);

	std::shared_ptr<Array<T>> copy();

	void sortThisUp();
	void sortThisDown();
	std::shared_ptr <Array<T>> sortCopyUp();
	std::shared_ptr <Array<T>> sortCopyDown();

	T operator [](size_t index);
};