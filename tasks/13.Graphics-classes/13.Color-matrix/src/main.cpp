#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Color Matrix")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	Vector_ref<Rectangle> rects;
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			rects.push_back(new Rectangle(Point(i * 20, j * 20), 20, 20));
			rects[rects.size() - 1].set_fill_color(i * 16 + j);
			rects[rects.size() - 1].set_color(Color::invisible);
			window.attach(rects[rects.size() - 1]);
		}
	}

	window.wait_for_button();
}
