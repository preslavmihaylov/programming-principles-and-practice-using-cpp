#ifndef REGULAR_POLY_H
#define REGULAR_POLY_H

#include "Graph.h"

class Regular_polygon : public Graph_lib::Polygon {
public:
	Regular_polygon(Point center, double sidesCnt, double centerDistance, double startingAngle);
	Point getCenter() const { return this->center; }
	double getSidesCnt() const { return this->sidesCnt; }
	double getSideLength() const { return this->sideLength; }
	double getCenterDistance() const { return this->centerDistance; }
private:
	Point center;
	double sidesCnt;
	double centerDistance;
	double sideLength;
};

#endif // REGULAR_POLY_H
