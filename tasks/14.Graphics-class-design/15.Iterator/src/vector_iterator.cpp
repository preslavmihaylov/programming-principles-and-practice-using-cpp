#include "vector_iterator.h"

double* Vector_iterator::next()
{
	if (currentIndex < this->vect.size())
	{
		return &this->vect[currentIndex++];
	}
	else
	{
		return 0;
	}
}
