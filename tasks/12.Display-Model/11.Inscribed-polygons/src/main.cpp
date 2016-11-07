#include <math.h> 

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("Inscribed polygons")

#define POLYGONS_CNT (8)

static Point origin(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
static double radius = 200;

// angle is in radians
Point GetCurrentVertexCoordinate(double angle)
{
	//double y = cos(angle) * radius + origin.y;
	//double x = sin(angle) * radius + origin.x;
	double y = sin(-angle) * radius + origin.y;
	double x = cos(angle) * radius + origin.x;
	return Point(x, y);
}

// Take middle point of two polygon vertices and calculate distance from that point to the origin. That is the new radius
void MakeInscribedCircle(const Point & polygonPoint1, const Point & polygonPoint2)
{
	Point middlePoint((polygonPoint1.x + polygonPoint2.x) / 2.0,
					  (polygonPoint1.y + polygonPoint2.y) / 2.0);

	double distanceX = origin.x - middlePoint.x;
	double distanceY = origin.y - middlePoint.y; 
	double newRadius = sqrt((distanceX * distanceX) + (distanceY * distanceY));
	radius = newRadius;
}

void DrawRegularPolygon(Simple_window & window, Polygon & polygon, int dimensions, double startingAngle)
{
	double interiorAngle = (2 * M_PI) / dimensions; // regular polygons have equal inscribed angle
	Point polygonPoint1(0, 0);
	Point polygonPoint2(0, 0);

	window.attach(polygon);
	for (int cnt = 0; cnt < dimensions; ++cnt)
	{
		Point currentPoint = GetCurrentVertexCoordinate(startingAngle);
		startingAngle += interiorAngle;
		polygon.add(currentPoint);

		if (cnt >=2)
		{
			window.wait_for_button();
		}

		polygonPoint1 = polygonPoint2;
		polygonPoint2 = currentPoint;
	}
	
	MakeInscribedCircle(polygonPoint1, polygonPoint2);
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	
	Polygon polygons[POLYGONS_CNT];
	
	double startingAngle = 0;
	// begin from 2 since there are no polygons with 2 sides
	for (int cnt = 0; cnt < POLYGONS_CNT; ++cnt)
	{
		// (Color::dark_cyan + 1) is the number of all colors
		polygons[cnt].set_color(cnt % (Color::dark_cyan + 1));
		polygons[cnt].set_style(Line_style(Line_style::solid, 5));
		DrawRegularPolygon(window, polygons[cnt], (POLYGONS_CNT - cnt) + 2, startingAngle);
		startingAngle += M_PI / 4;
	}
}
