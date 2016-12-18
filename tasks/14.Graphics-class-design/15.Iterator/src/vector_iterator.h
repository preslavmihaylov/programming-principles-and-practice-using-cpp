#ifndef VECTOR_ITERATOR_H
#define VECTOR_ITERATOR_H

#include "iterator.h"
#include <vector>

class Vector_iterator : public Iterator
{
public:
	Vector_iterator(std::vector<double>& vect)
		: vect(vect) {};
	double* next();
private:
	int currentIndex = 0;
	std::vector<double>& vect;
};

#endif // VECTOR_ITERATOR_H
