#include "smiley.h"

void Smiley::draw_lines() const
{
	Circle::draw_lines();
	
	Point center = this->center();
	int radius = this->radius();

	// left eyelid
	fl_arc(center.x - (radius / 6) - (radius / 2), 
		   center.y - (radius / 2), 
		   radius / 2, 
		   radius / 4, 0, 360);

	// left iris
	fl_arc(center.x - (radius / 6) - (radius / 3), 
		   center.y - (radius / 2), 
		   radius / 4, 
		   radius / 4, 0, 360);

	// right eyelid
	fl_arc(center.x + (radius / 6), 
		   center.y - (radius / 2), 
		   radius / 2, 
		   radius / 4, 0, 360);
	
	// right iris
	fl_arc(center.x + (radius / 6) + (radius / 2) - (radius / 3), 
		   center.y - (radius / 2), 
		   radius / 4, 
		   radius / 4, 0, 360);

	// Smile
	fl_arc(center.x - (radius / 2), 
		   center.y, 
		   radius, 
		   radius / 2, 180, 360);
}
