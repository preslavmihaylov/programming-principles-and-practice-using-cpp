#ifndef BOX_H
#define BOX_H

#include "arc.h"

#define DEFAULT_CORNER_RADIUS 5

class Box : public Graph_lib::Shape 
{
public:
	Box(Point topLeft, int width, int height)
		: tl(topLeft), w(width), h(height), cr(DEFAULT_CORNER_RADIUS) {};

	Box(Point topLeft, int width, int height, int cornerRadius)
		: tl(topLeft), w(width), h(height), cr(cornerRadius) {};
	
	Point topLeft() const { return tl; }
	int width() const { return w; }
	int height() const { return h; }

	void draw_lines() const;
private:
	Point tl;
	int w;
	int h;
	int cr;
};

#endif
