#include "box.h"

void Box::draw_lines() const
{
	// top left
	Arc tla(Point(tl.x + cr, tl.y + cr), cr, cr, 90, 180);
	// top right
	Arc tra(Point(tl.x + w - cr, tl.y + cr), cr, cr, 0, 90);
	// bottom left
	Arc bla(Point(tl.x + cr, tl.y + h - cr), cr, cr, 180, 270);
	// bottom right
	Arc bra(Point(tl.x + w - cr, tl.y + h - cr), cr, cr, 270, 360);

	tla.draw_lines();
	tra.draw_lines();
	bla.draw_lines();
	bra.draw_lines();
	
	// top
	fl_line((tl.x + cr), tl.y, ((tl.x + w) - cr), tl.y);
	// left
	fl_line(tl.x, (tl.y + cr), tl.x, ((tl.y + h) - cr));
	// bottom
	fl_line((tl.x + cr), (tl.y + h), ((tl.x + w) - cr), (tl.y + h));
	// right
	fl_line((tl.x + w), (tl.y + cr), (tl.x + w), ((tl.y + h) - cr));
}
