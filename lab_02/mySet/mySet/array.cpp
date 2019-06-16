#include <iostream>
#include "Ar_imp.h"
#include <string>

#define LOG(X) std::cout << X << std::endl
#define LINE std::cout << "-----------------------------" << std::endl

int array(void){
	Array<double> ad1;
	Array<int> ai1 { 1, 2, 3 };
	Array<char> ac1 = { 'a', 'b', 'c' };
	Array<std::string> as1(3);

	ad1.print();
	ai1.print();
	ac1.print();
	as1.print();
	LINE;

	ad1.reallocate(3);
	ad1.set(2, 4.5);
	ai1.remove(2);
	//ac1.sortThisDown();
	as1.append("hello");

	ad1.print();
	ai1.print();
	ac1.print();
	as1.print();
	LINE;

	Array<char> ac2 = ac1;
	ac2.print();
	ac1 = ac2;
	Array<int> ai2 = Array<int>(ai1);
	ai2.print();
	ai2.append(7);
	ai2.print_capacity();
	ai2.print_len();
	std::shared_ptr<Array<int>> ai3_p = ai2.clone();
	ai3_p->print();
	LOG(as1.is_empty());
	LOG(as1.is_enough());
	LOG(ac2.includes('a'));
	LOG(ai3_p->size());
	LOG(ai3_p->capacity());
	LOG(ai2.find(7));
	LOG(as1[0]);

	/*Array<double> ad2 = { 3.4, 6.2, 0.4, -3.4, -6.1 };
	Array<double> ad3 = ad2.sortCopyDown();
	Array<double> ad4 = ad2.sortCopyUp();
	ad2.sortThisDown();
	ad2.print();
	ad2.sortThisUp();
	ad2.print();
	ad3.print();
	ad4.print();*/

	Array<int> a7 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	a7.shiftLeft(0, 1);
	a7.print();

	return 0;
}