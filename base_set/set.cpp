#include <iostream>
#include "MySet_imp.h"

#define LOG(X) std::cout << X << std::endl
#define LINE std::cout << "-----------------------------" << std::endl

int main(void) {
	Set<int> tmp;
	tmp.append(5);
	tmp.append(1);
	LOG(tmp);
	try
	{
		LOG(tmp[1]);
		tmp.remove(3);
		tmp.remove(4);
		LOG(tmp[-1]);
	}
	catch (base_exception& exception)
	{
		std::cout << exception.what();
	}
	std::cout << std::endl << std::endl;

	Set<int> tmp_12 = { 1, 2, 3};
	for (auto i = tmp_12.inititalizeIterator(); i.check(); i++)
		std::cout << *i << std::endl;

	return 0;
}