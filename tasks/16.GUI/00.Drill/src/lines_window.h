#ifndef LINES_WINDOW_H
#define LINES_WINDOW_H

#include "GUI.h"
#include "Graph.h"

struct Lines_window : public Graph_lib::Window
{
	Lines_window(Point xy, int w, int h, const string& title);
private:
	Graph_lib::Out_box current_xy;
	Graph_lib::In_box x_next;
	Graph_lib::In_box y_next;
	Graph_lib::Button next_button;
	Graph_lib::Button quit_button;
	Graph_lib::Button color_menu_button;
	Graph_lib::Menu color_menu; 

	Graph_lib::Open_polyline lines;

	static void cb_color_menu_show(Graph_lib::Address, Graph_lib::Address pw);
	void color_menu_show();

	static void cb_red(Graph_lib::Address, Graph_lib::Address pw);
	void red();
	static void cb_blue(Graph_lib::Address, Graph_lib::Address pw);
	void blue();
	static void cb_black(Graph_lib::Address, Graph_lib::Address pw);
	void black();
	
	static void cb_next(Graph_lib::Address, Graph_lib::Address pw);
	void next();
	static void cb_quit(Graph_lib::Address, Graph_lib::Address pw);
	void quit();
};

#endif // LINES_WINDOW_H
