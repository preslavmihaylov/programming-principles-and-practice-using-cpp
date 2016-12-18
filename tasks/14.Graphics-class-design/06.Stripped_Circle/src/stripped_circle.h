#ifndef STRIPPED_CIRCLE_H
#define STRIPPED_CIRCLE_H

#include "Graph.h"

class Stripped_Circle : public Graph_lib::Circle
{
public:
	Stripped_Circle(Point center, int radius)
		: Graph_lib::Circle(center, radius) {};

	void draw_lines() const;
};

#endif // STRIPPED_CIRCLE_H
