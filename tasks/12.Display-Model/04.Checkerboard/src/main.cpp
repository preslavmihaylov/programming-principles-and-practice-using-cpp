#include <iostream>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define RECT_WIDTH (30)
#define RECT_HEIGHT RECT_WIDTH

Rectangle *** checkerboard; 

void InitCheckerboard(Simple_window & window, 
 				      Point startPos, 
					  int boardSize)
{
	checkerboard = new Rectangle**[boardSize];
	
	for (int row = 0; row < boardSize; ++row)
	{
		checkerboard[row] = new Rectangle*[boardSize];
		for (int col = 0; col < boardSize; ++col)
		{
			Color rectColor(Color::black);
			Point currentPos(startPos.x + RECT_WIDTH * col,
			                 startPos.y + RECT_HEIGHT * row);
			
			checkerboard[row][col] = new Rectangle(currentPos, 
			  									   RECT_WIDTH,
												   RECT_HEIGHT);
		
			if ((row + col) % 2 == 0)
			{
				rectColor = Color::red;
			}
			else
			{
				rectColor = Color::blue;
			}

			checkerboard[row][col]->set_fill_color(rectColor);	
			window.attach(*checkerboard[row][col]);
		}
	}
}

void DestroyCheckerboard(int boardSize)
{
	for (int row = 0; row < boardSize; ++row)
	{
		for (int col = 0; col < boardSize; ++col)
		{
			delete checkerboard[row][col];
		}
		
		delete checkerboard[row];
	}

	delete checkerboard;
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);

	Simple_window window(tl, 600, 400, "Rectangle");
	InitCheckerboard(window, Point(100, 100), 8);

	window.wait_for_button();
	DestroyCheckerboard(8);
}
