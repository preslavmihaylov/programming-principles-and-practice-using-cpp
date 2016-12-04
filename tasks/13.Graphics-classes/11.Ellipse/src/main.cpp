#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Ellipse")

#define ELLIPSE_XDIST (150)
#define ELLIPSE_YDIST (100)

double CalcEllipseFunc(double x, double xDist, double yDist)
{
	if (abs(x) > xDist)
	{
		error("Invalid x for ellipse function");
	}
	else
	{
		return yDist * sqrt(1 - ((x * x) / (xDist * xDist)));
	}
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	Point ellipseCenter = Point(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	Ellipse ellipse(ellipseCenter, ELLIPSE_XDIST, ELLIPSE_YDIST);
	Point focus1 = ellipse.focus1();
	Point focus2 = ellipse.focus2();
	double pointOnEllipseX = (ELLIPSE_XDIST - (ELLIPSE_XDIST / 2));
	double pointOnEllipseY = 
		CalcEllipseFunc(pointOnEllipseX, ELLIPSE_XDIST, ELLIPSE_YDIST);
	
	Point pointOnEllipse(pointOnEllipseX + ellipseCenter.x, pointOnEllipseY + ellipseCenter.y); 
	
	Line focus1Line(focus1, pointOnEllipse);
	Line focus2Line(focus2, pointOnEllipse);

	Mark centerMark(ellipseCenter, 'X');
	Mark focus1Mark(focus1, 'X');
	Mark focus2Mark(focus2, 'X');
	Mark pointOnEllipseMark(pointOnEllipse, 'X');

	Line xAxis(
			Point(ellipseCenter.x - 200, ellipseCenter.y), 
			Point(ellipseCenter.x + 200, ellipseCenter.y));
	Line yAxis(
			Point(ellipseCenter.x, ellipseCenter.y - 150),
			Point(ellipseCenter.x, ellipseCenter.y + 150));

	window.attach(ellipse);
	window.attach(xAxis);
	window.attach(yAxis);
	window.attach(focus1Line);
	window.attach(focus2Line);
	window.attach(centerMark);
	window.attach(focus1Mark);
	window.attach(focus2Mark);
	window.attach(pointOnEllipseMark);
	window.wait_for_button();
}
