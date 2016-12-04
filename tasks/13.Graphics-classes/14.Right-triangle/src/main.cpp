#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "right_triangle.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Right triangles")

#define OCTAGON_X_ORIGIN (400)
#define OCTAGON_Y_ORIGIN (400)

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	// draw octagon
	Right_triangle tri1(
		Point(OCTAGON_X_ORIGIN, OCTAGON_Y_ORIGIN), 
		100, 
		200, 
		0);
	
	Right_triangle tri2(
		Point(OCTAGON_X_ORIGIN + 100, OCTAGON_Y_ORIGIN - 200), 
		100, 
		200, 
		M_PI);

	Right_triangle tri3(
		Point(OCTAGON_X_ORIGIN + 150, OCTAGON_Y_ORIGIN - 150),
		200,
		100,
		M_PI);
	
	Right_triangle tri4(
		Point(OCTAGON_X_ORIGIN - 50, OCTAGON_Y_ORIGIN - 50),
		200,
		100,
		M_PI * 2);
	
	Right_triangle tri5(
		Point(OCTAGON_X_ORIGIN, OCTAGON_Y_ORIGIN - 50),
		50,
		50,
		M_PI);
	
	Right_triangle tri6(
		Point(OCTAGON_X_ORIGIN + 100, OCTAGON_Y_ORIGIN - 50),
		50,
		50,
		M_PI / 2);
	
	Right_triangle tri7(
		Point(OCTAGON_X_ORIGIN, OCTAGON_Y_ORIGIN - 150),
		50,
		50,
		M_PI * 3 / 2);
	
	Right_triangle tri8(
		Point(OCTAGON_X_ORIGIN + 100, OCTAGON_Y_ORIGIN - 150),
		50,
		50,
		0);

	window.attach(tri1);
	window.attach(tri2);
	window.attach(tri3);
	window.attach(tri4);
	window.attach(tri5);
	window.attach(tri6);
	window.attach(tri7);
	window.attach(tri8);
	window.wait_for_button();
}
