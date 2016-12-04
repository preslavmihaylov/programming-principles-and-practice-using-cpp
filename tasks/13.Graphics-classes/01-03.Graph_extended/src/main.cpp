#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "arc.h"
#include "box.h"

using namespace std;

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Arc")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	Arc a(Point(200, 200), 50, 100, 0, 360);
	Box b1(Point(300, 300), 100, 100, 20);
	Box b2(Point(500, 500), 200, 300, 30);
	
	window.attach(b1);
	window.attach(b2);
	window.attach(a);
	window.wait_for_button();
}
