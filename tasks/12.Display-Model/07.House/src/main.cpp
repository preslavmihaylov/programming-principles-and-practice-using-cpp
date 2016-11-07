#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("House")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);

	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	
	// Draw ground
	double groundWidth = 100;
	Rectangle ground(Point(0, SCREEN_HEIGHT - groundWidth), 
	                 SCREEN_WIDTH, 
					 groundWidth);

	ground.set_fill_color(Color::green);
	window.attach(ground);

	// Draw House basis
	double houseWidth = 200;
	double houseHeight = 200;
	double houseStartX = SCREEN_WIDTH / 6.0;
	double houseStartY = SCREEN_HEIGHT - (groundWidth / 2.0) - houseHeight;
	Rectangle houseBasis(Point(houseStartX, houseStartY),
						 houseWidth,
						 houseHeight);

	houseBasis.set_fill_color(Color::yellow);
	window.attach(houseBasis);

	// Draw house window 1
	Rectangle window1(Point(houseStartX + 30, houseStartY + 30),
					  50,
					  50);

	window1.set_fill_color(Color::blue);

	window.attach(window1);

	// Draw house window 2
	Rectangle window2(Point((houseStartX + houseWidth) - 80, houseStartY + 30),
					  50,
					  50);

	window2.set_fill_color(Color::blue);

	window.attach(window2);

	// Draw house door
	double houseDoorWidth = houseWidth / 4.0;
	double houseDoorHeight = houseHeight / 3.0;
	double houseDoorX = houseStartX + ((houseWidth / 2) - (houseDoorWidth / 2));
	double houseDoorY = houseStartY + (houseHeight - houseDoorHeight);
	Rectangle houseDoor(Point(houseDoorX, houseDoorY), 
	 				    houseDoorWidth, 
						houseDoorHeight);

	houseDoor.set_fill_color(Color::dark_red);
	window.attach(houseDoor);

	// Draw house roof
	Polygon houseRoof;
	Point leftmostPoint(houseStartX - (houseWidth / 4.0), houseStartY);
	Point rightmostPoint(houseStartX + houseWidth + (houseWidth / 4.0), houseStartY);
	Point topmostPoint((houseWidth / 2) + houseStartX, houseStartY - (houseHeight / 2.0));
	
	houseRoof.add(leftmostPoint);
	houseRoof.add(rightmostPoint);
	houseRoof.add(topmostPoint);

	houseRoof.set_fill_color(Color::dark_red);
	window.attach(houseRoof);
	window.wait_for_button();
}
