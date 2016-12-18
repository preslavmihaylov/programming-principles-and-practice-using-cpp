#include "GUI.h"
#include "lines_window.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("Lines")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Lines_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	return gui_main();
}
