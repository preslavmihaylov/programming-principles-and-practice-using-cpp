#include "checkerbox_window.h"

#define BOARD_ROWS (4)
#define BOARD_COLS (4)
#define BOARD_START_X (100)
#define BOARD_START_Y (100)
#define BOARD_CELL_WIDTH (30)
#define BOARD_CELL_HEIGHT (30)

using namespace Graph_lib;

Checkerbox_window::Checkerbox_window(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	  output(Point(50, 50), 100, 30, "Output"),
	  quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit)
{
	for (int row = 0; 
		 row <= (BOARD_ROWS * BOARD_CELL_WIDTH); 
		 row += BOARD_CELL_WIDTH)
	{
		for (int col = 0;
		 col <= (BOARD_COLS * BOARD_CELL_HEIGHT);
			 col += BOARD_CELL_HEIGHT)
		{
			Point currentPoint(col + BOARD_START_Y, row + BOARD_START_X);
			this->board.push_back(
				new Button(currentPoint, 
						   BOARD_CELL_WIDTH, 
						   BOARD_CELL_HEIGHT,
						   "Click",
						   cb_hide_cell));
			
			attach(this->board[this->board.size() - 1]);
		}
	}

	attach(output);
	attach(quit_button);
};

void Checkerbox_window::cb_hide_cell(Graph_lib::Address callee, 
								     Graph_lib::Address pw)
{
	Button& b = Graph_lib::reference_to<Button>(callee);
	Graph_lib::reference_to<Checkerbox_window>(pw).hide_cell(b);
}

void Checkerbox_window::hide_cell(Graph_lib::Button& callee)
{
	for (int i = 0; i < this->board.size(); ++i)
	{
		this->board[i].show();
	}

	output.put(std::to_string(callee.loc.x));
	//redraw();
}

void Checkerbox_window::cb_quit(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<Checkerbox_window>(pw).quit();
}

void Checkerbox_window::quit()
{
	hide();
}
