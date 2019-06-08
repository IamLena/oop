// mySet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myArray.h"

#define LOG(X) std::cout << X << std::endl
int main()
{
	Array<int> ar;
	LOG(ar.size());
	LOG(ar.capacity());

	ar.fillZeros();
	ar.fillRange(3, 8, 2);
	ar.append(3);
	ar.append(0);
	LOG(ar.capacity());
	ar.print();

	//ar.sortThis();
	//ar.print();
	std::shared_ptr<Array<int>> ar2 = ar.copy();
	ar2->print();
	ar2 = ar.sortCopy();
	ar2->print();


	Array<int> ar3{ 1, 2, 3 };
	ar3.print();
	std::cin.get();
	return 0;
}