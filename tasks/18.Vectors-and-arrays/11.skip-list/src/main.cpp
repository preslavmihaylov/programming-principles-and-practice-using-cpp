#include <iostream>
#include "skip_list.h"

using namespace std;

int main()
{
	SkipList sl;
	sl.insertVal(5, 0);
	sl.insertVal(15, 2);
	sl.insertVal(10, 0);
	sl.insertVal(20, 1);
	sl.insertVal(40, 3);

	cout << sl << endl;
	/*
	cout << "Is 5 present? " << sl.findVal(5) << endl;
	cout << "Is 15 present? " << sl.findVal(15) << endl;
	cout << "Is 10 present? " << sl.findVal(10) << endl;
	cout << "Is 20 present? " << sl.findVal(20) << endl;
	cout << "Is 40 present? " << sl.findVal(40) << endl;
	cout << "Is 25 present? " << sl.findVal(25) << endl;
	*/

	/*
	sl.deleteVal(15);
	cout << "15 deleted" << endl;
	cout << sl << endl;
	
	sl.deleteVal(40);
	cout << "40 deleted" << endl;
	cout << sl << endl;
	
	sl.deleteVal(4);
	cout << "4 deleted (does not exist)" << endl;
	cout << sl << endl;
	*/

	SkipList sl1 = sl;
	SkipList sl2;
	sl2.insertVal(5, 2);
	sl2.insertVal(20, 1);
	sl2.insertVal(50, 5);
	sl2.insertVal(100, 3);
	sl2.insertVal(200, 0);
	sl2 = sl;
	cout << "OLD LIST" << endl;
	cout << sl << endl;
	cout << "copy constructor" << endl;
	cout << sl1 << endl;
	cout << "copy assignment" << endl;
	cout << sl2 << endl;

	return 0;
}
