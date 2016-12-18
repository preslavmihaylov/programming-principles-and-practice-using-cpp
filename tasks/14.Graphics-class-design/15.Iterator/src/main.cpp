#include <iostream>
#include <vector>

using namespace std;

#include "vector_iterator.h"

void print(Iterator& iter)
{
	double* currentElement;
	while ((currentElement = iter.next()) != NULL)
	{
		cout << *currentElement << endl;
	}
}

int main()
{
	vector<double> vect;
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(5);
	vect.push_back(6);

	Vector_iterator iter(vect);
	print(iter);

	return 0;
}
