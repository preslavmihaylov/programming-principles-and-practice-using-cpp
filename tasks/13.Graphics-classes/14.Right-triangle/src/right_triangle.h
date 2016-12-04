#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "Graph.h"

typedef enum
{
	eNorth,
	eSouth
} Triangle_orientation;

class Right_triangle : public Graph_lib::Shape 
{
public:
	Right_triangle(Point rightAngleVertex, 
				   double xEdgeLength, 
				   double yEdgeLength,
				   // In radians
				   double rotation);
};

#endif // RIGHT_TRIANGLE_H
