#pragma once
#include <memory>
#include <iostream>

namespace base {
	class BaseContainer {
	protected:
		size_t m_count;
	public:
		BaseContainer();
		explicit BaseContainer(size_t count);
		virtual ~BaseContainer();

		bool is_empty() const;
		size_t get_size() const;
	};

	template <typename T>
	class Iterator {
	public:
		Iterator();
		explicit Iterator(int size, std::shared_ptr<T>& ptr);
		explicit Iterator(int size, T* ptr);
		Iterator(const Iterator<T>& iter);
		Iterator<T>& operator = (const Iterator<T>& iter);
		~Iterator();

		Iterator<T>& operator ++ ();
		Iterator<T>& operator -- ();
		Iterator<T> operator ++ (int i);
		Iterator<T> operator -- (int i);
		Iterator<T>& operator += (int i);
		Iterator<T>& operator -= (int i);
		Iterator<T> operator + (int num) const;
		Iterator<T> operator - (int num) const;

		bool operator == (const Iterator<T>& iter) const;
		bool operator != (const Iterator<T>& iter) const;
		bool operator < (const Iterator<T>& iter) const;
		bool operator <= (const Iterator<T>& iter) const;
		bool operator > (const Iterator<T>& iter) const;
		bool operator >= (const Iterator<T>& iter) const;
		T get_value() const;
		friend std::ostream& operator<< (std::ostream& os, const Iterator<T>& iter) {
			os << iter.get_value();
			return os;
		}

	private:
		std::weak_ptr<T> beg;
		int m_index;
		int m_size;
	};

	class ConstIterator {

	};
}