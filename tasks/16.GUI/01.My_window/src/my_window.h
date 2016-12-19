#ifndef MY_WINDOW_H
#define MY_WINDOW_H

#include "GUI.h"
#include "Graph.h"

struct My_window : public Graph_lib::Window
{
	My_window(Point xy, int w, int h, const string& title);
private:
	Graph_lib::Button next_button;
	Graph_lib::Button quit_button;

	static void cb_next(Graph_lib::Address, Graph_lib::Address pw);
	void next();
	static void cb_quit(Graph_lib::Address, Graph_lib::Address pw);
	void quit();
};

#endif // MY_WINDOW_H
