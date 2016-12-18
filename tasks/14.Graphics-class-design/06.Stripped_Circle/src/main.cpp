#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "stripped_circle.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Stripped rectangle")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	Stripped_Circle sc(Point(300, 300), 200);
	sc.set_fill_color(Color::dark_red);

	window.attach(sc);
	window.wait_for_button();
}
