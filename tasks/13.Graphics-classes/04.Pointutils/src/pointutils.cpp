#include "pointutils.h"

Point n(Graph_lib::Rectangle& rect)
{
	Point tl = rect.point(0);
	return Point(tl.x + (rect.width() / 2), tl.y);
}

Point s(Graph_lib::Rectangle& rect)
{
	Point tl = rect.point(0);
	return Point(tl.x + (rect.width() / 2), tl.y + rect.height());
}

Point e(Graph_lib::Rectangle& rect)
{
	Point tl = rect.point(0);
	return Point(tl.x + rect.width(), tl.y + (rect.height() / 2));
}

Point w(Graph_lib::Rectangle& rect)
{
	Point tl = rect.point(0);
	return Point(tl.x, tl.y + (rect.height() / 2));
}


Point center(Graph_lib::Rectangle& rect)
{
	Point tl = rect.point(0);
	return Point(tl.x + (rect.width() / 2), tl.y + (rect.height() / 2));
}

Point ne(Graph_lib::Rectangle& rect)
{
	Point tl = rect.point(0);
	return Point(tl.x + rect.width(), tl.y);
}
Point se(Graph_lib::Rectangle& rect)
{
	Point tl = rect.point(0);
	return Point(tl.x + rect.width(), tl.y + rect.height());
}

Point sw(Graph_lib::Rectangle& rect)
{
	Point tl = rect.point(0);
	return Point(tl.x, tl.y + rect.height());
}

Point nw(Graph_lib::Rectangle& rect)
{
	return rect.point(0);
}
