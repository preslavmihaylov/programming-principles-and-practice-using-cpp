#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "group.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Group")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	Group gr;
	Rectangle rect(Point(100, 100), 100, 100);	
	gr.add(rect);
	
	window.attach(rect);
	window.wait_for_button();

	gr.move(150, 150);
	window.wait_for_button();
}
