#include "stripped_rect.h"

using namespace Graph_lib;

#define LINE_SPACING (7)

void Stripped_Rectangle::draw_lines() const
{
	int w = this->width();
	int h = this->height();

    if (color().visibility()) {    // lines on top of fill
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,w,h);
    }

	int startX = point(0).x;
	int startY = point(0).y;
	for (int cnt = startY; cnt < startY + h; cnt += LINE_SPACING)
	{ 
		fl_line(startX, cnt, startX + this->width(), cnt);
	}
}
