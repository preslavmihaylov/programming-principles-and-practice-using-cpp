#include "right_triangle.h"

using namespace Graph_lib;

Right_triangle::Right_triangle(Point rightAngleVertex, 
				   			   double xEdgeLength, 
				   			   double yEdgeLength,
				   			   // In radians
				   			   double rotation)
{
	double yOffset;
	double xOffset;

	// yEdge
	yOffset = yEdgeLength * sin(rotation - (M_PI / 2));
	xOffset = yEdgeLength * cos(rotation - (M_PI / 2));
	Point yEdge(rightAngleVertex.x + xOffset, rightAngleVertex.y + yOffset);

	// xEdge
	yOffset = xEdgeLength * sin(rotation);
	xOffset = xEdgeLength * cos(rotation);
	Point xEdge(rightAngleVertex.x + xOffset, rightAngleVertex.y + yOffset);
	
	add(rightAngleVertex);
	add(yEdge);
	add(xEdge);
	add(rightAngleVertex);
}
