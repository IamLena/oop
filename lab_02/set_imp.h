#pragma once
#include "set.h"

template <typename T>
void Set<T>::print() const {
	if (this->m_length == 0) {
		std::cout << "Empty set\n";
		return;
	}
	std::cout << "Set: ";
	for (size_t i = 0; i < this->m_length; i++) {
		std::cout << *(this->m_ptr + i) << " ";
	}
	std::cout << '\n';
}

template <typename T>
int Set<T>::append(T element) {
	int rc;
	if (!this->is_enough()) {
		rc = this->reallocate(this->m_length + 1);
		if (rc == -1) { return -1; }
	}
	if (this->find(element) == -1) {
		this->m_ptr[this->m_length] = element;
		this->m_length += 1;
		return 0;
	}
	return 1;
}

template <typename T>
std::shared_ptr <Set<T>> Set<T>::sortCopyUp() {
	std::shared_ptr <Set<T>> tmp = this->copy();
	qsort(tmp->m_ptr, tmp->m_length, sizeof(tmp->m_ptr[0]), compUp<T>);
	return tmp;
}

template <typename T>
std::shared_ptr <Set<T>> Set<T>::sortCopyDown() {
	std::shared_ptr <Set<T>> tmp = this->copy();
	qsort(tmp->m_ptr, tmp->m_length, sizeof(tmp->m_ptr[0]), compDown<T>);
	return tmp;
}

template <typename T>
std::shared_ptr<Set<T>> Set<T>::copy() {
	std::shared_ptr<Set<T>> tmp = std::shared_ptr<Set<T>>(new Set<T>);
	if (tmp->reallocate(this->capacity()) == 0) {
		tmp->m_length = this->m_length;
		for (size_t i = 0; i < tmp->m_length; i++) {
			*(tmp->m_ptr + i) = *(this->m_ptr + i);
		}
	}
	else {
		std::cout << "bad allocation" << std::endl;
	}

	return tmp;
}