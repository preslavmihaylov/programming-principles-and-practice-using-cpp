#include <math.h> 

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (1200)
#define SCREEN_HEIGHT (900)
#define SCREEN_TITLE ("Superellipse")

#define FCT_SCALE 50

#define X_POWER 5.0
#define Y_POWER 3.0
#define X_RADIUS 6.0
#define Y_RADIUS 4.0

#define POINTS_CNT 6

static Point * points[POINTS_CNT];
static Line ** lines;
static int glinksCnt;

static double SuperEllipseEq(double x)
{
	return pow( pow(abs(Y_RADIUS), Y_POWER) * (1 - pow(abs(x / X_RADIUS), X_POWER)), 1 / Y_POWER);
}

static double SuperEllipseNegativeEq(double x)
{
	return -pow( pow(abs(Y_RADIUS), Y_POWER) * (1 - pow(abs(x / X_RADIUS), X_POWER)), 1 / Y_POWER);
}

static void GeneratePoints(const Point & startingPoint)
{
	double pointDistance = 2 * X_RADIUS / (POINTS_CNT / 2);
	double currentXValue = -X_RADIUS;
	double currentYValue;
	int step = 1;
	

	for (int cnt = 0; cnt < POINTS_CNT; ++cnt)
	{
		if (step % 2 == 0)
		{
			currentYValue = SuperEllipseEq(currentXValue);
		}
		else
		{
			currentYValue = SuperEllipseNegativeEq(currentXValue);
		}

		points[cnt] = new Point(startingPoint.x + (currentXValue * FCT_SCALE), startingPoint.y + (currentYValue * FCT_SCALE));

		if (step % 2 == 1)
		{
			currentXValue += pointDistance;
		}
		++step;
	}
}

static void GenerateLines(Simple_window & window)
{
	// formula for arithmetic series S = N * (A + An) / 2
	glinksCnt = ((POINTS_CNT - 1) * POINTS_CNT) / 2;
	lines = new Line*[glinksCnt];

	int lineIndex = 0;
	// connect all N points to every (N - 1) points
	for (int cnt = 0; cnt < POINTS_CNT; ++cnt)
	{
		for (int innerCnt = cnt + 1; innerCnt < POINTS_CNT; ++innerCnt)
		{
			lines[lineIndex] = new Line(*points[cnt], *points[innerCnt]);
			// (Color::dark_cyan + 1) is the number of all colors
			lines[lineIndex]->set_color(lineIndex % (Color::dark_cyan + 1));
			lines[lineIndex]->set_style(Line_style(Line_style::solid, 4));

			window.attach(*lines[lineIndex]);
			++lineIndex;
		}
	}
}

static void DestroyResources()
{
	int cnt;
	for (cnt = 0; cnt < POINTS_CNT; ++cnt)
	{
		delete points[cnt];
	}

	for (cnt = 0; cnt < glinksCnt; ++cnt)
	{
		delete lines[cnt];
	}

	delete lines;
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	Point startingPoint(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0);

	Function superEllipseFct(SuperEllipseEq, -X_RADIUS, X_RADIUS + 0.01, startingPoint, 10000, FCT_SCALE, FCT_SCALE);
	Function superEllipseNegativeFct(SuperEllipseNegativeEq, -X_RADIUS, X_RADIUS + 0.01, startingPoint, 10000, FCT_SCALE, FCT_SCALE);
	
	// function styles
	superEllipseFct.set_style(Line_style(Line_style::solid, 4));
	superEllipseNegativeFct.set_style(Line_style(Line_style::solid, 4));

	startingPoint.x -= X_RADIUS;
	GeneratePoints(startingPoint);
	GenerateLines(window);

	window.attach(superEllipseFct);
	window.attach(superEllipseNegativeFct);
	window.wait_for_button();

	DestroyResources();
}
