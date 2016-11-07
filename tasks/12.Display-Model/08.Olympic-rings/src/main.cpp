#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("Olympic rings")

#define OLYMPIC_RINGS_CNT (5)

Color ringColors[] = 
{
	Color::blue,
	Color::yellow,
	Color::black,
	Color::green,
	Color::red
};

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	Rectangle background(Point(0, 0), SCREEN_WIDTH, SCREEN_HEIGHT);
	background.set_fill_color(Color::dark_red);
	window.attach(background);
	
	Point startPoint(SCREEN_WIDTH / 4.0, SCREEN_HEIGHT / 2.0);
	int ringRadius = 50;
	int circleDistance = 60;
	Circle * circles[OLYMPIC_RINGS_CNT];

	for (int index = 0; index < OLYMPIC_RINGS_CNT; ++index)
	{
		Point circlePoint(startPoint.x + (index * circleDistance), startPoint.y + ((index % 2) * circleDistance));
		circles[index] = new Circle(circlePoint, ringRadius);
		
		circles[index]->set_color(ringColors[index]);
		circles[index]->set_style(Line_style(Line_style::solid, 8));

		window.attach(*circles[index]);
	}

	window.wait_for_button();
	
	// Destroy resources
	for (int index = 0; index < OLYMPIC_RINGS_CNT; ++index)
	{
		delete circles[index];
	}
}
