#ifndef HEXAGON_H
#define HEXAGON_H

#include "Graph.h"
#include "regular_poly.h"

#define HEXAGON_SIDES_CNT (6)

class Hexagon : public Regular_polygon {
public:
	Hexagon(Point center, double centerDistance) :
		Regular_polygon(center, HEXAGON_SIDES_CNT, centerDistance, 0) {};
};

#endif // HEXAGON_H
