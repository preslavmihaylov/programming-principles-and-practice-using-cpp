#ifndef FLYING_IMG_WINDOW_H
#define FLYING_IMG_WINDOW_H

#include "GUI.h"
#include "Graph.h"

struct FlyingImg_window : public Graph_lib::Window
{
	FlyingImg_window(Point xy, int w, int h, const string& title);
private:
	Graph_lib::Button quit_button;
	Graph_lib::Image img;

	// callbacks
	static void cb_updateImgPos(Graph_lib::Address data);
	void updateImgPos();
	static void cb_quit(Graph_lib::Address callee, Graph_lib::Address pw);
	void quit();

	int xQuantifier = 1;
	int yQuantifier = 1;
};

#endif // FLYING_IMG_WINDOW_H
