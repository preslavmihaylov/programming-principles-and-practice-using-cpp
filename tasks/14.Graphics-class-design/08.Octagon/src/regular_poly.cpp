#include "regular_poly.h"
#include <cmath>

Point GetCurrentVertexCoordinate(const Point& center, double centerDistance, double angle)
{
	double y = sin(-angle) * centerDistance + center.y;
	double x = cos(angle) * centerDistance + center.x;
	return Point(x, y);
}

Regular_polygon::Regular_polygon(Point center, 
								 double sidesCnt, 
								 double centerDistance, 
								 double startingAngle)
{
	if (sidesCnt < 3 || centerDistance <= 0)
	{
		error("Bad polygon");
	}
	this->sidesCnt = sidesCnt;
	this->center = center;
	this->centerDistance = centerDistance;

	// regular polygons have equal inscribed angle
	double interiorAngle = (2 * M_PI) / this->sidesCnt; 
	Point firstPoint;
	Point secondPoint;

	for (int cnt = 0; cnt < sidesCnt; ++cnt)
	{
		Point currentPoint = 
			GetCurrentVertexCoordinate(this->center, this->centerDistance, startingAngle);
		startingAngle += interiorAngle;
		add(currentPoint);
		
		firstPoint = secondPoint;
		secondPoint = currentPoint;
		if (cnt == 1)
		{
			int yDiff = secondPoint.y - firstPoint.y;
			int xDiff = secondPoint.x - firstPoint.x;
			this->sideLength = sqrt((xDiff * xDiff) + (yDiff * yDiff));
		}
	}
}
