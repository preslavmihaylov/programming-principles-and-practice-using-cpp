#include "Simple_window.h"
#include "Graph.h"

#include "binary_tree.h"
#include "tri_binary_tree.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Binary tree")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	Tri_Binary_tree bt(Point(500, 500), 5, 20, 20);
	window.attach(bt);
	window.wait_for_button();
}
