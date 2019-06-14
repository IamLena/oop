#include <iostream>
#include "set_imp.h"

int main(void) {
	Set<int> s0;
	Set<char> s1(4);
	Set<double> s2 = { 1, 2.3, 4.2 };
	Set<std::string> s3{ "hello", "world" };

	s0.append(2);
	s0.append(3);
	Set<int> s4 = s0;
	Set<int> s5 = { 4, 5, 2 };

	Set<int> u;
	//s4 {2, 3}
	//s5 {4, 5, 2}
	u = s4 + s5;
	Set<int> inter = s4.intersection(s5);

	s4.print();
	s5.print();
	u.print();
	inter.print();
	Set<int> d;
	d = s5 - s4;
	d.print();
	return 0;
}