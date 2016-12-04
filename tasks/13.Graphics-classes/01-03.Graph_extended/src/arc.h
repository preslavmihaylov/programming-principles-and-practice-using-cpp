#ifndef ARC_H
#define ARC_H

#include "Graph.h"

class Arc : public Graph_lib::Shape {
public:
	Arc(Point center, int width, int height, double startAngle, double endAngle)
		: x(center.x - width), 
		  y(center.y - height), 
		  w(width), 
		  h(height), 
		  sa(startAngle), 
		  ea(endAngle) {};

	Point center() const { return Point(x + w, y + h); }
	int width() const { return w; }
	int height() const { return h; }
	double startAngle() const { return sa; }
	double endAngle() const { return ea; }
	void draw_lines() const;
private:
	int x;
	int y;
	int w;
	int h;
	double sa;
	double ea;
};

#endif
