#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Drill")

#define CELL_WIDTH (100)
#define CELL_HEIGHT (CELL_WIDTH)
#define CELLS_CNT_H (8)
#define CELLS_CNT_V (CELLS_CNT_H)
#define GRID_WIDTH (CELL_WIDTH * CELLS_CNT_H)
#define GRID_HEIGHT (CELL_HEIGHT * CELLS_CNT_V)

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	Lines grid;
	Vector_ref<Rectangle> rects;
	for (int row = 0; row <= GRID_HEIGHT; row += CELL_HEIGHT)
	{
		for (int col = 0; col <= GRID_WIDTH; col += CELL_WIDTH)
		{
			// horizontal line
			grid.add(Point(0, row), Point(GRID_WIDTH, row));
			// vertical line
			grid.add(Point(col, 0), Point(col, GRID_HEIGHT));

			// is on the diagonal
			if ((row / CELL_HEIGHT) == (col / CELL_WIDTH))
			{
				rects.push_back(
					new Rectangle(Point(col, row), CELL_WIDTH, CELL_HEIGHT));
				rects[rects.size() - 1].set_fill_color(Color::red);
				window.attach(rects[rects.size() - 1]);
			}
		}
	}
	
	// Images
	Image img1(Point(0, CELL_HEIGHT * 3), "./res/pic.jpg");
	Image img2(Point(CELL_WIDTH * 3, 0), "./res/pic.jpg");
	Image img3(Point(CELL_WIDTH * 3, CELL_HEIGHT * 6), "./res/pic.jpg");

	// moving duck

	window.attach(grid);
	window.attach(img1);
	window.attach(img2);
	window.attach(img3);

	srand(time(NULL));
	for (;;)
	{
		int x = (rand() % (CELLS_CNT_H)) * CELL_WIDTH;
		int y = (rand() % (CELLS_CNT_V)) * CELL_HEIGHT;
		Image * duckImg = new Image(Point(x, y), "./res/duck.jpg");
		window.attach(*duckImg);
		window.wait_for_button();
		window.detach(*duckImg);
		delete duckImg;
	}
}
