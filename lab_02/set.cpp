#include <iostream>
#include "set_imp.h"

#define LOG(X) std::cout << X << std::endl
#define LINE std::cout << "-----------------------------" << std::endl

int main(void) {
	Set<int> s0 = { 1, 4, 2, 5, 7 };
	Set<int> s1 = { 1, 4, 3, 6 };

	LOG("s0");
	s0.print();
	LOG("s1");
	s1.print();
	LINE;

	LOG("union");
	Set<int> u0 = s0 + s1;
	Set<int> u1 = s0.unionMethod(s1);
	Set<int> u2 = s1.unionMethod(s0);

	u0.print();
	u1.print();
	u2.print();

	LOG((u0 == u1));
	LOG((u0 == u2));
	LOG((u1 == u2));
	LOG((u0 != u1));
	LINE;
	LOG("substraction");
	Set<int> d0 = s0 - s1;
	Set<int> d1 = s0.substraction(s1);
	Set<int> d2 = s1.substraction(s0);

	d0.print();
	d1.print();
	d2.print();

	LOG((d0 == d1));
	LOG((d0 == d2));
	LOG((d1 == d2));
	LOG((d0 != d1));
	LINE;

	LOG("intersection");
	Set<int> n1 = s0.intersection(s1);
	Set<int> n2 = s1.intersection(s0);

	n1.print();
	n2.print();

	LOG((n1 == n2));
	LOG((n2 == n1));
	LOG((n2 != n1));
	LINE;

	LOG("s0");
	s0.print();
	LOG("s1");
	s1.print();
	LINE;

	Set<int> tmp_12 = { 12, 14, 125 };
	for (auto i = tmp_12.inititalizeIterator(); i.check(); i++)
		std::cout << *i << std::endl;

	return 0;
}