#include <iostream>
#include "base.h"
#include "animals.h"
#include "some-answers.h"
using namespace std;
int main() {
	char c = 'q';
	do {
		cout << "\nEnter to choose:\n"
			"\t1 - overrided_and_inherited\n"
			"\t2 - definition_virtual\n"
			"\t3 - smart_pointers\n"
			"\t4 - safely_type_conversion\n"
			"\t5 - examples\n"
			"\t6 - classnames\n"
			"\t7 - isInstances\n"
			"\t8 - not_safe_type_conversion\n"
			"\t9 - base and desc\n"
			"\tq - to quit\n";
		cin >> c;
		switch (c) {
		case '1':
			overrided_and_inherited();
			break;
		case '2':
			definition_virtual();
			break;
		case '3':
			smart_pointers();
			break;
		case '4':
			safely_type_conversion();
			break;
		case '5':
			examples();
			break;
		case '6':
			classnames();
			break;
		case '7':
			isInstances();
			break;
		case '8':
			not_safe_type_conversion();
			break;
		case '9':
			base();
			break;
		}
	} while (c != 'q');
	return 0;
}