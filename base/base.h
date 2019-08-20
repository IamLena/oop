#pragma once
#include <memory>
#include <iostream>

namespace base {
	class BaseContainer {
	protected:
		size_t m_size;
		void set_size(int size);
	public:
		BaseContainer();
		explicit BaseContainer(size_t count);
		virtual ~BaseContainer();

		bool is_empty() const;
		size_t get_size() const;
	};

	template <typename T>
	class BaseIterator {
	protected:
		std::weak_ptr<T> m_ptr;
		size_t m_index;
	public:
		BaseIterator(std::shared_ptr<T> ptr, size_t index = 0);
		BaseIterator(const BaseIterator<T>& iter);
		virtual ~BaseIterator();

		BaseIterator<T>& operator = (const BaseIterator<T>& iter);
		
		BaseIterator<T>& operator ++ ();
		BaseIterator<T>& operator -- ();
		BaseIterator<T>& operator ++ (int i);
		BaseIterator<T>& operator -- (int i);
		BaseIterator<T>& operator += (int i);
		BaseIterator<T>& operator -= (int i);
		BaseIterator<T> operator +  (int i) const;
		BaseIterator<T> operator - (int i) const;

		bool operator == (const BaseIterator<T>& iter) const;
		bool operator != (const BaseIterator<T>& iter) const;
	};

	template <typename T>
	class Iterator : public BaseIterator<T> {
	public:
		Iterator(std::shared_ptr<T> ptr, size_t index = 0);
		Iterator(const Iterator<T>& iter);

		T* get_ptr();
		const T* get_ptr() const;
		T get_value ();
		const T get_value () const;
	};

	template <typename T>
	class ConstIterator : public BaseIterator<T> {
	public:
		ConstIterator(std::shared_ptr<T> ptr, size_t index = 0);
		ConstIterator(const ConstIterator<T>& iter);

		const T* get_ptr() const;
		const T get_value() const;
	};
}