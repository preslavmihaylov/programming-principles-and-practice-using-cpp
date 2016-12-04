#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "pointutils.h"

using namespace std;

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Pointutils")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	Rectangle rect(Point(100, 100), 200, 100);
	Marks rectPoints("12345678");

	rectPoints.add(nw(rect));
	rectPoints.add(n(rect));
	rectPoints.add(ne(rect));
	rectPoints.add(e(rect));
	rectPoints.add(se(rect));
	rectPoints.add(s(rect));
	rectPoints.add(sw(rect));
	rectPoints.add(w(rect));
	
	window.attach(rectPoints);
	window.attach(rect);
	window.wait_for_button();
}
