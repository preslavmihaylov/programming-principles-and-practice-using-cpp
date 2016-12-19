#include "GUI.h"
#include "currencyConverter_window.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("Currency converter")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	CurrencyConverter_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	return gui_main();
}
