// mySet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myArray_imp.h"
#include "set_imp.h"

#define LOG(X) std::cout << X << std::endl
#define LINE std::cout << "-----------------------------" << std::endl

int main()
{
	Set<int> s0 { 3, 7, 1, 0 };
	s0.sortThisDown();
	s0.print();
	LINE;
	Set<char> set0;
	set0.print_len();
	set0.print_capacity();
	LINE;
	set0.fillRange('o', 'v', 2);
	set0.print();

	Set<char> set1(10);
	set1.print_len();
	set1.print_capacity();
	set1.append('1');
	set1.append('2');
	
	set1.reallocate(3);
	set1.print_len();
	set1.print_capacity();
	set1.print();
	set1.append('7');
	set1.append('0');
	set1.print_len();
	set1.print_capacity();
	set1.print();
	set1.sortThisUp();
	set1.print();
	set1.sortThisDown();
	set1.print();
	LINE;

	Set<char> set2{ 'd', 'e', 'f' };
	set2.print_len();
	set2.print_capacity();
	Set<char> set4 = set2;
	set4.print();
	std::shared_ptr<Array<char>> set3 = set2.sortCopyDown();
	set3->print();
	LINE;
	int er = set2.append('e');
	LOG(er);


	std::cin.get();
	return 0;
}