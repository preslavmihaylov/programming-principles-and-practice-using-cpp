#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);

	Simple_window window(tl, 600, 400, "Rectangle");

	// Initial 'P'
	Line pHorizontal1(Point(100, 100), Point(100, 250));
	Line pHorizontal2(Point(175, 100), Point(175, 175));
	Line pVertical1(Point(100, 100), Point(175, 100));
	Line pVertical2(Point(100, 175), Point(175, 175));

	// Initial 'P' - Line style
	pHorizontal1.set_style(Line_style(Line_style::solid, 3));
	pHorizontal2.set_style(Line_style(Line_style::solid, 3));
	pVertical1.set_style(Line_style(Line_style::solid, 3));
	pVertical2.set_style(Line_style(Line_style::solid, 3));
	
	// Initial 'P' - Color
	pHorizontal1.set_color(Color::blue);
	pHorizontal2.set_color(Color::blue);
	pVertical1.set_color(Color::blue);
	pVertical2.set_color(Color::blue);

	// Initial 'M'
	Line mHorizontal1(Point(200, 100), Point(200, 250));
	Line mHorizontal2(Point(350, 100), Point(350, 250));
	Line mDiagonal1(Point(200, 100), Point(275, 175));
	Line mDiagonal2(Point(275, 175), Point(350, 100));
	
	// Initial 'M' - Line style
	mHorizontal1.set_style(Line_style(Line_style::solid, 3));
	mHorizontal2.set_style(Line_style(Line_style::solid, 3));
	mDiagonal1.set_style(Line_style(Line_style::solid, 3));
	mDiagonal2.set_style(Line_style(Line_style::solid, 3));

	// Initial 'M' - Color
	mHorizontal1.set_color(Color::red);
	mHorizontal2.set_color(Color::red);
	mDiagonal1.set_color(Color::red);
	mDiagonal2.set_color(Color::red);
	
	window.attach(pHorizontal1);
	window.attach(pHorizontal2);
	window.attach(pVertical1);
	window.attach(pVertical2);
	
	window.attach(mHorizontal1);
	window.attach(mHorizontal2);
	window.attach(mDiagonal1);
	window.attach(mDiagonal2);
	
	window.wait_for_button();
}
