#ifndef SMILEY_H
#define SMILEY_H

#include "Graph.h"

class Smiley : public Graph_lib::Circle
{
public:
	Smiley(Point center, int radius)
		: Graph_lib::Circle(center, radius) {};
	void draw_lines() const;
};

#endif // SMILEY_H
