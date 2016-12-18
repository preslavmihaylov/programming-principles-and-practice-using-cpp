#include "stripped_circle.h"

using namespace Graph_lib;

#define LINE_SPACING (7)

int getCircleX(Point center, int radius, int y, int quantifier)
{
	// (x - cx)^2 + (y-cy)^2 = r^2
	int yOffset = y - center.y;
	return (quantifier * sqrt((radius * radius) - (yOffset * yOffset)))
			+ center.x;
}

void Stripped_Circle::draw_lines() const
{
	Circle::draw_lines();
	Point center = this->center();
	int radius = this->radius();

	for (int currentY = (center.y - radius); 
	     currentY < (center.y + radius); 
		 currentY += LINE_SPACING)
	{
		int x = getCircleX(center, radius, currentY, -1);
		int destX = getCircleX(center, radius, currentY, 1);
		fl_line(x, currentY, destX, currentY);
	}
}
