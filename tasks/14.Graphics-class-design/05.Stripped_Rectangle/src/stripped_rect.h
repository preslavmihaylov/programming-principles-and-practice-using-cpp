#ifndef STRIPPED_RECT_H
#define STRIPPED_RECT_H

#include "Graph.h"

class Stripped_Rectangle : public Graph_lib::Rectangle
{
public:
	Stripped_Rectangle(Point xy, int ww, int hh)
		: Graph_lib::Rectangle(xy, ww, hh) {};

	void draw_lines() const;
};

#endif // STRIPPED_RECT_H
