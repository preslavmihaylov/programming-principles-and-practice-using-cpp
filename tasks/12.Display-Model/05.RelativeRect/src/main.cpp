#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (400)
#define SCREEN_TITLE ("Relative Rectangle")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);

	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	double rectWidth = (2 * SCREEN_WIDTH / 3.0);
	double rectHeight = (3 * SCREEN_HEIGHT / 4.0);
	double startX = (SCREEN_WIDTH - rectWidth) / 2;
	double startY = (SCREEN_HEIGHT - rectHeight) / 2;

	Rectangle rect(Point(startX, startY), rectWidth, rectHeight);
	rect.set_fill_color(Color::blue);
	rect.set_style(Line_style(Line_style::solid, 2));
	rect.set_color(Color::red);

	window.attach(rect);
	window.wait_for_button();
}
