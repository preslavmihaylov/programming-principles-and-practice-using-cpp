#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

#include "regular_poly.h"
#include "hexagon.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Hexagons")

#define X_OFFSET (200)
#define Y_OFFSET (200)
#define CELLS_CNT_H (8)
#define CELLS_CNT_V (8)
#define HEXAGON_CENTER_DIST (50)

Vector_ref<Hexagon> hexagons;
static void DrawTiledHexagons(Simple_window& window)
{
	int halfSideLength = Hexagon(Point(0, 0), HEXAGON_CENTER_DIST).getSideLength() / 2;
	int colOffset = halfSideLength + HEXAGON_CENTER_DIST;
	int hexagonCenterToBottomDist = 
				sqrt(
					(HEXAGON_CENTER_DIST * HEXAGON_CENTER_DIST) - 
					(halfSideLength * halfSideLength)
				);
	int rowOffset = 2 * hexagonCenterToBottomDist;
	int currentCenterX;
	int currentCenterY;
	
	for (int row = 0; row < CELLS_CNT_V; ++row)
	{
		for (int col = 0; col < CELLS_CNT_H; ++col)
		{
			currentCenterY = Y_OFFSET + (row * rowOffset);
			currentCenterX = X_OFFSET + (col * colOffset);
			// Tile hexagon with bigger Y on each odd col
			if (col % 2 == 1)
			{
				currentCenterY += hexagonCenterToBottomDist;
			}

			hexagons.push_back(
				new Hexagon(
					Point(currentCenterX, currentCenterY), 
					HEXAGON_CENTER_DIST));

			hexagons[hexagons.size() - 1].set_fill_color(
				Color(((row * CELLS_CNT_H + col) * 20) % 255));
			window.attach(hexagons[hexagons.size() - 1]);
		}
	}
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	
	DrawTiledHexagons(window);
	window.wait_for_button();
}
