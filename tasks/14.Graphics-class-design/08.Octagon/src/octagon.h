#ifndef OCTAGON_H
#define OCTAGON_H

#include "Graph.h"
#include "regular_poly.h"

#define OCTAGON_SIDES_CNT (8)

class Octagon : public Regular_polygon {
public:
	Octagon(Point center, double centerDistance) :
		Regular_polygon(center, OCTAGON_SIDES_CNT, centerDistance, 0) {};
};

#endif // OCTAGON_H
