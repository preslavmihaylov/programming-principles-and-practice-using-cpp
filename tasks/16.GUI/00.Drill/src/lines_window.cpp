#include "lines_window.h"

using namespace Graph_lib;

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	  current_xy(Point(100, 0), 100, 20, "current (x,y):"), 
	  x_next(Point(x_max() - 310, 0), 50, 20, "next x:"), 
	  y_next(Point(x_max() - 210, 0), 50, 20, "next y:"), 
	  next_button(Point(x_max() - 150, 0), 70, 20, "Next point", cb_next),
	  quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
	  color_menu_button(Point(x_max() - 70, 40), 70, 20, "color menu", cb_color_menu_show),
	  color_menu(Point(x_max() - 70, 40), 70, 20, Menu::vertical, "color")
{
	attach(current_xy);
	attach(x_next);
	attach(y_next);
	attach(next_button);
	attach(quit_button);
	attach(lines);
	attach(color_menu_button);

	color_menu.attach(new Button(Point(0, 0), 0, 0, "red", cb_red));
	color_menu.attach(new Button(Point(0, 0), 0, 0, "blue", cb_blue));
	color_menu.attach(new Button(Point(0, 0), 0, 0, "black", cb_black));
	attach(color_menu);

	color_menu.hide();
};

void Lines_window::cb_color_menu_show(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<Lines_window>(pw).color_menu_show();
}

void Lines_window::color_menu_show()
{
	color_menu.show();
	color_menu_button.hide();
}

void Lines_window::cb_red(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<Lines_window>(pw).red();
}

void Lines_window::red()
{
	this->lines.set_color(Color::red);
	color_menu.hide();
	color_menu_button.show();
}

void Lines_window::cb_blue(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<Lines_window>(pw).blue();
}

void Lines_window::blue()
{
	this->lines.set_color(Color::blue);
	color_menu.hide();
	color_menu_button.show();
}
	
void Lines_window::cb_black(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<Lines_window>(pw).black();
}

void Lines_window::black()
{
	this->lines.set_color(Color::black);
	color_menu.hide();
	color_menu_button.show();
}

void Lines_window::cb_next(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<Lines_window>(pw).next();
}

void Lines_window::next()
{
	int x = x_next.get_int();
	int y = y_next.get_int();
	
	stringstream ss;
	ss << "(" << x << "," << y << ")";
	current_xy.put(ss.str());

	lines.add(Point(x, y));
	redraw();
}

void Lines_window::cb_quit(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<Lines_window>(pw).quit();
}

void Lines_window::quit()
{
	hide();
}
