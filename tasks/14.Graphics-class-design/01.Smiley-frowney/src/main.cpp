#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "smiley.h"
#include "frowney.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Smiley-Frowney")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	Smiley smiley(Point(300, 300), 200);
	Frowney frowney(Point(750, 300), 200);
	window.attach(smiley);
	window.attach(frowney);
	window.wait_for_button();
}
