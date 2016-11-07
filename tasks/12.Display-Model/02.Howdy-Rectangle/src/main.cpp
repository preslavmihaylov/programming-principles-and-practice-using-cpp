#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

void DrawRect(Simple_window & window, Rectangle & rect)
{
	rect.set_color(Color::blue);	
	window.attach(rect);		
}

void DrawText(Simple_window & window, Text & text)
{
	text.set_color(Color::red);
	window.attach(text);
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);

	Simple_window window(tl, 600, 400, "Rectangle");
	Rectangle rect(Point(100, 100), 100, 30);
	Text howdyText(Point(120, 120), "Howdy!");

	DrawRect(window, rect);
	DrawText(window, howdyText);

	window.wait_for_button();
}
