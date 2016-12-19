#ifndef ANALOG_CLOCK_WINDOW_H
#define ANALOG_CLOCK_WINDOW_H

#include "GUI.h"
#include "Graph.h"

struct AnalogClock_window : public Graph_lib::Window
{
	AnalogClock_window(Point xy, int w, int h, const string& title);
	~AnalogClock_window();
private:
	Graph_lib::Button quit_button;
	Graph_lib::Mark m;

	Graph_lib::Circle clock;
	Graph_lib::Line * hours_line;
	Graph_lib::Line * minutes_line;
	Graph_lib::Line * seconds_line;

	// callbacks
	static void cb_updateClock(Graph_lib::Address data);
	void updateClock();
	static void cb_quit(Graph_lib::Address callee, Graph_lib::Address pw);
	void quit();

	// local functions
	void destroyResources();
	void initClock();
};

#endif // ANALOG_CLOCK_WINDOW_H
