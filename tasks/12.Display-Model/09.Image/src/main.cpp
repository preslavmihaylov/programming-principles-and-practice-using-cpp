#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("C++ rocks")

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	Rectangle background(Point(0, 0), SCREEN_WIDTH, SCREEN_HEIGHT);
	background.set_fill_color(Color::dark_red);
	window.attach(background);

	// Render image
	double imageX = SCREEN_WIDTH / 4.0;
	double imageY = SCREEN_HEIGHT / 4.0;

	Image image(Point(imageX, imageY), "image.jpg");
	window.attach(image);
	
	// Render caption
	Text text(Point(imageX + 100, imageY - 10), "Who's your daddy?");
	text.set_font_size(120);
	text.set_color(Color::blue);

	window.attach(text);
	window.wait_for_button();
}
