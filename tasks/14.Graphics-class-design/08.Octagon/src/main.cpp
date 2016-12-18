#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "regular_poly.h"
#include "octagon.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Octagon")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	
	Octagon oct(Point(300, 300), 200);
	window.attach(oct);
	window.wait_for_button();
}
