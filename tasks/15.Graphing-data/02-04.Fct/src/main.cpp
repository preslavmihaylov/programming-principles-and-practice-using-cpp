#include "Simple_window.h"
#include "Graph.h"
#include "fct.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("Fct Example")

double sinCosSum(double x) { return sin(x) + cos(x); }
double sinCosSquare(double x) { return sin(x) * sin(x) + cos(x) * cos(x); }

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

	Func sinFct(sin, -10, 11, orig, 400, xScale, yScale);    
	Func cosFct(cos, -10, 11, orig, 400, xScale, yScale);    
	Func sinCosSumFct(sinCosSum, -10, 11, orig, 400, xScale, yScale);    
	Func sinCosSquareFct(sinCosSquare, -10, 11, orig, 400, xScale, yScale);    
	
	window.attach(sinFct);
	window.attach(cosFct);
	window.attach(sinCosSumFct);
	window.attach(sinCosSquareFct);
	window.wait_for_button();
}
