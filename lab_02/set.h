#pragma once
#include "Ar_imp.h"

template <typename T>
class Set : public Array<T>
{
public:
	//constructors
	Set() : Array<T>() {};
	Set(size_t length) : Array<T>(length) {};
	Set(const std::initializer_list<T>& list) : Array<T>(list) {};

	//copy
	Set(const Set& another);
	Set<T>* clone() const;

	//print
	void print() const;
	
	int append(T element);
	
	
	//check
	bool operator ==(const Set<T>& another_set) const;
	bool operator !=(const Set<T>& another_set) const;

	//set operations
	Set<T> unionMethod(Set<T>& another_set) const;
	Set<T> operator + (Set<T>& another_set) const;

	Set<T> intersection(Set<T>& another_set) const;

	Set<T> substraction(Set<T>& another_set) const;
	Set<T> operator - (Set<T>& another_set) const;
};