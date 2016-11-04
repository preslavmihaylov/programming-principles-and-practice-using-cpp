#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

void DrawRectPoly(Simple_window & window, Polygon & poly)
{
	poly.add(Point(100, 200));
	poly.add(Point(100, 100));
	poly.add(Point(200, 100));
	poly.add(Point(200, 200));
	poly.set_color(Color::red);

	window.attach(poly);
}

void DrawRect(Simple_window & window, Rectangle & rect)
{
	rect.set_color(Color::blue);	
	window.attach(rect);		
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);

	Simple_window window(tl, 600, 400, "Rectangle");
	Polygon poly;
	Rectangle rect(Point(300, 100), 100, 100);
	
	DrawRectPoly(window, poly);
	DrawRect(window, rect);
	window.wait_for_button();
}
