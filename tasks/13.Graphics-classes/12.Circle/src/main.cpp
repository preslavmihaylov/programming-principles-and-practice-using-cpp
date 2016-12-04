#include <math.h> 
#include <cstdlib>
#include <ctime>

#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (1000)
#define SCREEN_HEIGHT (1000)
#define SCREEN_TITLE ("Circle")

#define CIRCLE_CENTER_X (SCREEN_WIDTH / 2)
#define CIRCLE_CENTER_Y (SCREEN_HEIGHT / 2)
#define CIRCLE_RADIUS (100)
#define CIRCLE_MARK_STEP (20)

double CalcCircleFunc(double x, double radius, double quantifier)
{
	return quantifier * sqrt(radius * radius - x * x);
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	
	Circle circle(Point(CIRCLE_CENTER_X, CIRCLE_CENTER_Y), CIRCLE_RADIUS);
	window.attach(circle);
	
	double currentX = 0;
	double currentY;
	int circleMarkStep = CIRCLE_MARK_STEP;
	int quantifier = 1;
	while (true)
	{
		currentY = CalcCircleFunc(currentX, CIRCLE_RADIUS, quantifier);
		Mark pointOnCircleMark(
			Point(currentX + CIRCLE_CENTER_X, currentY + CIRCLE_CENTER_Y), 
			'X');
		
		window.attach(pointOnCircleMark);
		window.wait_for_button();
		window.detach(pointOnCircleMark);
		
		currentX += circleMarkStep;
		if (abs(currentX) > CIRCLE_RADIUS)
		{
			circleMarkStep = -circleMarkStep;
			currentX += 2 * circleMarkStep;
			quantifier = -quantifier;
		}
	}
}
