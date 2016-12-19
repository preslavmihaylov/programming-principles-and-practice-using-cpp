#include "flyingImg_window.h"

using namespace Graph_lib;

#define ANIM_FREQ_S (0.5)
#define X_VELOCITY (50)
#define Y_VELOCITY (50)
#define IMG_WIDTH (50)
#define IMG_HEIGHT (50)

FlyingImg_window::FlyingImg_window(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	  img(Point(x_max() / 2, y_max() / 2), "img.jpg"),
	  quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit)
{
	img.set_mask(Point(0, 0), IMG_WIDTH, IMG_HEIGHT);

	attach(img);
	attach(quit_button);
	Fl::add_timeout(ANIM_FREQ_S, cb_updateImgPos, this);
};

void FlyingImg_window::cb_updateImgPos(Address data)
{
	Graph_lib::reference_to<FlyingImg_window>(data).updateImgPos();
}

void FlyingImg_window::updateImgPos()
{
	yQuantifier = -yQuantifier;
	if (((img.point(0).x + X_VELOCITY + IMG_WIDTH) > x_max()) ||
		((img.point(0).x + X_VELOCITY - IMG_WIDTH) < 0))
	{
		xQuantifier = -xQuantifier;
	}

	img.move(X_VELOCITY * xQuantifier,Y_VELOCITY * yQuantifier);
	Fl::redraw();
	Fl::add_timeout(ANIM_FREQ_S, cb_updateImgPos, this);
}

void FlyingImg_window::cb_quit(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<FlyingImg_window>(pw).quit();
}

void FlyingImg_window::quit()
{
	hide();
}
