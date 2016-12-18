#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "animal.h"
#include "Dog.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Abstract classes")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	
	// Animal animal; - this will cause error. Pure virtual func.
	Dog dog; // this works. virtual func is overriden
	Circle c(Point(100, 100), 50);
	// Circle c1 = c; - error. Shape copy constructor is private

	window.wait_for_button();
}
