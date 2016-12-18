#ifndef FROWNEY_H
#define FROWNEY_H

#include "Graph.h"

class Frowney : public Graph_lib::Circle
{
public:
	Frowney(Point center, int radius)
		: Graph_lib::Circle(center, radius) {};
	void draw_lines() const;
};

#endif // FROWNEY_H
