#ifndef CHECKERBOX_WINDOW_H
#define CHECKERBOX_WINDOW_H

#include "GUI.h"
#include "Graph.h"

struct Checkerbox_window : public Graph_lib::Window
{
	Checkerbox_window(Point xy, int w, int h, const string& title);
private:
	Graph_lib::Button quit_button;
	Graph_lib::Vector_ref<Graph_lib::Button> board;
	Graph_lib::Out_box output;
	
	static void cb_hide_cell(Graph_lib::Address callee, 
							 Graph_lib::Address pw);
	void hide_cell(Graph_lib::Button& callee);
	static void cb_quit(Graph_lib::Address callee, Graph_lib::Address pw);
	void quit();
};

#endif // CHECKERBOX_WINDOW_H
