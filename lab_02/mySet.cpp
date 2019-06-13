// mySet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "myArray_imp.h"
#include "set_imp.h"

#define LOG(X) std::cout << X << std::endl
#define LINE std::cout << "-----------------------------" << std::endl

int main()
{
	Set<char> set0;
	Set<char> set1(4);
	Set<char> set2{ '1', '6', '3' };

	set1.append('3');
	set1.append('4');
	set1.append('2');
	set1.append('3');

	set2.print();
	set1.print();
	LINE;
	//set0 = set1.unionMethod(set2);
	Set<char> set4;
	set4 = set2 + set1;
	set2.print();
	set1.print();
	set4.print();
	LINE;

	Set<int> a0 { 1, 2, 3 };
	Set<int> a1{ 3, 4 };

	Set<char> s1{ '1', '2', '3' };
	Set<char> *s2 = s1.clone();
	Set<char>s3{ '3', 'a', '2', '7' };
	s1.print();
	s2->print();
	s3.print();
	//Set<char> s4 = s1.intersection(s3);

	Set<int> sin1 = { 1, 2, 3 };
	sin1.sortThisUp();
	sin1.print();
	sin1.append(5);
	//sin1.shift(1, 1);
	sin1.print();

	return 0;
}