#ifndef IMAGEBUTTON_WINDOW_H
#define IMAGEBUTTON_WINDOW_H

#include "GUI.h"
#include "Graph.h"

struct ImageButton_window : public Graph_lib::Window
{
	ImageButton_window(Point xy, int w, int h, const string& title);
private:
	Graph_lib::Button quit_button;
	Graph_lib::Button main_button;
	Graph_lib::Image main_button_img;

	static void cb_moveButton(Graph_lib::Address, Graph_lib::Address pw);
	void moveButton();
	static void cb_quit(Graph_lib::Address callee, Graph_lib::Address pw);
	void quit();
};

#endif // IMAGEBUTTON_WINDOW_H
