#include "imageButton_window.h"

using namespace Graph_lib;

#define BUTTON_WIDTH (100)
#define BUTTON_HEIGHT (50)

int rint(int low, int high)
{
	return (low + (rand()%(high - low)));
}

ImageButton_window::ImageButton_window(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	  main_button(Point(rint(0, x_max() - BUTTON_WIDTH), rint(0, y_max() - BUTTON_HEIGHT)), 
	  			  BUTTON_WIDTH, BUTTON_HEIGHT, "Click", cb_moveButton),
	  main_button_img(Point(this->main_button.loc.x, this->main_button.loc.y), 
	  			  "img.jpg"),
	  quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit)
{
	main_button_img.set_mask(Point(0, 0), BUTTON_WIDTH, BUTTON_HEIGHT);
	attach(main_button);
	attach(main_button_img);
	attach(quit_button);
};

void ImageButton_window::cb_moveButton(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<ImageButton_window>(pw).moveButton();
}
	
void ImageButton_window::moveButton()
{
	Point newPos(rint(0, x_max() - BUTTON_WIDTH), rint(0, y_max() - BUTTON_HEIGHT));
	Point oldPos = this->main_button.loc;
	this->main_button.move(newPos.x - oldPos.x, newPos.y - oldPos.y);
	this->main_button_img.move(newPos.x - oldPos.x, newPos.y - oldPos.y);
}

void ImageButton_window::cb_quit(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<ImageButton_window>(pw).quit();
}

void ImageButton_window::quit()
{
	hide();
}
