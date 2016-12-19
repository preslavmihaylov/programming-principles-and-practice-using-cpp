#include "GUI.h"
#include "imageButton_window.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("Image Button window")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	ImageButton_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	return gui_main();
}
