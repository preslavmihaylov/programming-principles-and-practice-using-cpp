#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("RGB Chart")

#define ROW_OFFSET (50)
#define CELL_WIDTH (75)
#define CELL_HEIGHT (25)
#define CELLS_CNT_H (6)
#define CELLS_CNT_V (38)
#define GRID_WIDTH (CELL_WIDTH * CELLS_CNT_H)
#define GRID_HEIGHT (CELL_HEIGHT * CELLS_CNT_V)

#define MONO_ROWS_CNT (2)
#define HALF_BYTE_CNT (4)

Vector_ref<Rectangle> rects;

typedef struct tRGBColor
{
	unsigned char Red;
	unsigned char Green;
	unsigned char Blue;
} RGBColor;

static RGBColor CalcRGB(int row, int col)
{
	RGBColor resColor;
	
	if (row < MONO_ROWS_CNT)
	{
		// first cell is 15, second is 14...
		int currentCell = 0x0E - (row * CELLS_CNT_H + col);

		resColor.Red = resColor.Green = resColor.Blue
			// 0x0Y --> 0xYY
			= (currentCell << HALF_BYTE_CNT) | currentCell;
	}
	else
	{
		row -= MONO_ROWS_CNT;
		resColor.Red = (row % CELLS_CNT_H) * 0x33;
		resColor.Green = (row / CELLS_CNT_H) * 0x33;
		resColor.Blue = col * 0x33;
	}
	return resColor;
}

static void CreateRGBChart(Simple_window& window)
{
	Lines grid;
	for (int row = 0; row < CELLS_CNT_V; ++row)
	{
		for (int col = 0; col < CELLS_CNT_H; ++col)
		{
			rects.push_back(
				new Rectangle(
					Point(col * CELL_WIDTH, row * CELL_HEIGHT), 
					CELL_WIDTH, 
				 	CELL_HEIGHT));

			RGBColor rgbColor = CalcRGB(row, col);
			rects[rects.size() - 1].set_fill_color(
				fl_rgb_color(rgbColor.Red, rgbColor.Green, rgbColor.Blue));
			window.attach(rects[rects.size() - 1]);
		}
	}
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	CreateRGBChart(window);
	window.wait_for_button();
}
