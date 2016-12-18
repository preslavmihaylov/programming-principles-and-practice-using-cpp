#include "Simple_window.h"
#include "Graph.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("Function graphs")

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double slopping_cos(double x) { return (cos(x) + slope(x)); }

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	int axisWidth = 400;
	int xScale = 20;
	int yScale = 20;

	Point orig(300, 300);

	Axis xAxis(Axis::x, 
			   Point((SCREEN_WIDTH - axisWidth) / 2, SCREEN_HEIGHT / 2), 
			   axisWidth, 
			   20, 
			   "1 == 20 pixels");	
	
	Axis yAxis(Axis::y, 
			   Point(SCREEN_WIDTH / 2, 
			   	     SCREEN_HEIGHT - (SCREEN_HEIGHT - axisWidth) / 2), 
			   axisWidth, 
			   20, 
			   "1 == 20 pixels");	

	xAxis.set_color(Color::red);
	yAxis.set_color(Color::red);
	window.attach(xAxis);
	window.attach(yAxis);

	Function oneFct(one, -10, 11, orig, 400, xScale, yScale);    
	Function slopeFct(slope, -10, 11, orig, 400, xScale, yScale);    
	Function squareFct(square, -10, 12, orig, 400, xScale, yScale);    
	Function cosFct(cos, -10, 12, orig, 400, xScale, yScale);    
	Function sloppingCosFct(slopping_cos, -10, 12, orig, 400, xScale, yScale);    
	Text slopeLabel(Point(orig.x - (10 * xScale),
						  orig.y - (slope(-10) * yScale) - 20), 
					"x/2");

	window.attach(oneFct);
	window.attach(slopeFct);
	window.attach(squareFct);
	window.attach(cosFct);
	window.attach(sloppingCosFct);
	window.attach(slopeLabel);
	window.wait_for_button();
}
