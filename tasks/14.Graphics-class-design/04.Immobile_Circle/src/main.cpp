#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "immobile_circle.h"
using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Immobile Circle")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	
	Circle c(Point(100, 100), 100);
	Immobile_Circle c1(Point(100, 100), 100);
	c.move(300, 300);
	// c1.move(300, 300); // this fails

	window.attach(c);
	window.attach(c1);
	window.wait_for_button();
}
