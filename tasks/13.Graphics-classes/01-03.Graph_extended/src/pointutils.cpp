#include "pointutils.h"

Point n(Rectangle rect)
{
	Point tl = rect.point(0);

	return Point(tl.x + (rect.width() / 2), tl.y);
}

/*
Point s(Rectangle rect);
Point e(Rectangle rect);
Point w(Rectangle rect);
Point center(Rectangle rect);
Point ne(Rectangle rect);
Point se(Rectangle rect);
Point sw(Rectangle rect);
Point nw(Rectangle rect);
*/
